# Simulate a sports tournament

import csv
import math
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    with open(sys.argv[1], 'r') as filename:
        csv_file = csv.DictReader(filename)
        for row in csv_file:
            teams.append(row)

    for team in teams:
        team['rating'] = int(team['rating'])
    
    counts = {}
    for i in range(N):
        team_name = simulate_tournament(teams)
        
        if team_name in counts:
            counts[team_name] += 1
        else:
            counts[team_name] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
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

def simulate_tournament(teams)-> str:
    """Simulate a tournament. Return name of winning team."""
    tmp_teams = teams
    while (math.log2(len(tmp_teams)) != 0):
        tmp_teams = simulate_round(tmp_teams)
    
    for index, element in enumerate(tmp_teams):
        return element['team']

if __name__ == "__main__":
    main()
