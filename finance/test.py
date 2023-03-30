import os
#export API_KEY=pk_43a3b169c8f74b93afcad22c6a97cdf0
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd


hashed = werkzeug.security.generate_password_hash("shush", method='pbkdf2:sha256', salt_length=8)

print(hashed)
