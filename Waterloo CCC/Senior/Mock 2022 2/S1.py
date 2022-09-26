from math import inf
from itertools import product

ins = input().split()
lines = int(ins[0])
testLength = int(ins[1])

answers = set()
for i in range(int(lines)):
    answers.add(input())

answers = list(answers)
maxMinScore = 0

# try every combination of answers
answerKeys = list(product('TF', repeat=testLength))

for answerKey in answerKeys:
    minScore = inf
    for i in range(len(answers)):
        score = 0
        for j in range(testLength):
            if answerKey[j] == answers[i][j]:
                score += 1
        if score < minScore:
            minScore = score
    if minScore > maxMinScore:
        maxMinScore = minScore

print(maxMinScore)