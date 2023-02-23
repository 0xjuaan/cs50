# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 45

def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # : Read teams into memory from file

    with open("2018m.csv") as dict:
        dict_reader = csv.DictReader(dict)
        for line in dict_reader:
            teams.append(line)


    counts = {}
    # : Simulate N tournaments and keep track of win counts

    #First populating the counts dict
   # for j in range(len(teams)):
        #counts[teams[j]["team"]] = int(0)

    for i in range(N):
        winner = simulate_tournament(teams)

        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 0



    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

    return 0

def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((int(rating2) - int(rating1)) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    #
    left = []
    right = []

    #Splitting the teams into left and right of tree
    for i in range(len(teams)):
        if i < len(teams) / 2:
            left.append(teams[i])
        else:
            right.append(teams[i])

    while len(left) != 1:
        left = simulate_round(left)
        right = simulate_round(right)


    if simulate_game(left[0], right[0]):
        return (left[0]["team"])
    else:
        return (right[0]["team"])



if __name__ == "__main__":
    main()
