def favTeamWining(favTeam, teams):
    for teamNum, team in enumerate(teams):
        if teamNum == favTeam:
            continue
        elif team >= teams[favTeam]:
            return False
    return True

favTeam = int(input())-1
gamesPlayed = int(input())
teams = [0, 0, 0, 0]
for game in range(gamesPlayed):
    scores = input().split()
    if scores[2] == scores[3]:
        teams[int(scores[0])-1] += 1
        teams[int(scores[1])-1] += 1
    elif int(scores[2]) > int(scores[3]):
        teams[int(scores[0])-1] += 3
    else:
        teams[int(scores[1])-1] += 3