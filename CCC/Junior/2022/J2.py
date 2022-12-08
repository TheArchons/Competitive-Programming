players = int(input())
stars = 0
for i in range(players):
    points = int(input())
    fouls = int(input())
    total = (points*5)-(fouls*3)
    if total > 40:
        stars+=1

if stars == players:
    print(players, end="")
    print("+")
else:
    print(stars)