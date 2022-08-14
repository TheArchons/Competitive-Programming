from math import inf

ins = input().split()
lines = int(ins[0])
testLength = int(ins[1])

answers = set()
for i in range(int(lines)):
    answers.add(input())

answers = list(answers)
maxMinScore = 0

for enumAnswer, answer in enumerate(answers):
    minScore = inf
    for i in range(len(answers)):
        score = 0
        for j in range(testLength):
            if answer[j] == answers[i][j]:
                score += 1
        if score < minScore:
            minScore = score
    if minScore > maxMinScore:
        maxMinScore = minScore

print(maxMinScore)