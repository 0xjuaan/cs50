import os
#export API_KEY=pk_43a3b169c8f74b93afcad22c6a97cdf0
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():

    alert = request.args.get('alert')

    if session.get("user_id") is None:
            return redirect("/login")

    stocks = db.execute("SELECT symbol,shares FROM stocks where id = ?", session["user_id"])

    total_stocks = 0
    for stock in stocks:
        data = lookup(stock["symbol"])

        stock["price"] = data["price"]
        stock["name"] = data["name"]
        stock["value"] = round(stock["price"]*stock["shares"], 2)

        total_stocks += stock["value"]

    cash = db.execute("SELECT cash FROM users where id = ?", session["user_id"])

    cash_send = {"key": "Cash" , "value": cash[0]['cash']}
    total = {"key": "GRAND TOTAL" , "value": total_stocks + cash_send['value']}
    footer = []
    footer.append(cash_send)
    footer.append(total)


    print(f"\n\n\n\n{cash}\n\n\n\n\n")

    return render_template("index.html", stocks=stocks, footer=footer, alert=alert)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    if request.method == "POST":
        #Getting values from the form post
        symbol = request.form.get("symbol")
        shares = float(request.form.get("shares"))

        #Getting stock data through API
        data = lookup(symbol)

        if data == None:
            return apology("Use a valid stock symbol")

        #Getting user's cash from database
        cash_dict = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        #def fix(money):
           #return money.replace("$", "").replace(",", "").replace(".", "")

        cash = float(cash_dict[0]['cash'])

        #Rendering errors before entering the buy into the database
        if float(shares) - round(float(shares)) !=0 or float(shares) < 1:
            return apology("The number of shares has to be a positive integer")

        if float(data["price"])*shares > cash:
            return apology("This order is too expensive.")

        #Subtracting the transaction cost from their cash value
        cash -= shares*data["price"]

        #Checking if they have already bought the stock or not
        def bought_stock(stock_symbol):
            past_shares = db.execute("SELECT shares FROM stocks WHERE symbol = ? AND id = ?", stock_symbol, session["user_id"])
            if past_shares == []:
                return False
            else:
                return True

        if not bought_stock(symbol):
            db.execute("INSERT INTO stocks (symbol, shares, id) VALUES (?, ?, ?)", symbol, shares, session["user_id"])
            db.execute("UPDATE users SET cash = ?  WHERE id = ?", cash, session["user_id"])
        else:
            #Adding to the existing number of shares
            db.execute("UPDATE stocks SET shares = shares + ? WHERE id = ? AND symbol = ?", shares, session["user_id"], symbol)
            #Updating the cash in 'users'
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

        # Redirect user to home page
        return redirect("/")

    else: # If the request method is "GET"
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        data = lookup(symbol)
        return render_template("quoted.html", data=data, price=data["price"])

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    #Function to check availability of username
    def available(val):
        names = db.execute("SELECT * FROM users WHERE username = ?", val)
        if len(names) > 0:
            return False
        else:
            return True


    #If they just got into the site via the link in top-right
    if request.method == "GET":
        return render_template("register.html")

    #If they posted into the form
    elif request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        vacant = available(username)

        if password == confirmation and vacant and password and confirmation and username:
            #Hashing password
            hashed = generate_password_hash(password, method='pbkdf2:sha256', salt_length=8)

            #inputting into database
            db.execute("INSERT INTO users (username, hash, cash) VALUES (?, ?, ?)", username, hashed, 10000)

            rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
            session["user_id"] = rows[0]["id"]

            return redirect(url_for('index', alert=f"Great! You have succesfully registered as {username}"))


        #Invalid inputs
        elif not vacant and password == confirmation:
            return apology(f"The username '{username}' is taken. Try another one.")
        elif vacant and password != confirmation:
            return apology(f"Passwords don't match.")
        else:
            return apology(f"Passwords don't match, and the username '{username} is taken. Or, you left a field blank")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "GET":
        symbols = db.execute("SELECT symbol FROM stocks WHERE id = ?", session["user_id"])

        return render_template("sell.html", symbols=symbols)
    """Sell shares of stock"""
    return apology("TODO")




#export API_KEY=pk_43a3b169c8f74b93afcad22c6a97cdf0