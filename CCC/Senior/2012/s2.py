romanVals = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

aromaticNum = input()
total = 0
multiplier = 0
for (i, j) in enumerate(aromaticNum):
    if (i%2):
        if (i+2 < len(aromaticNum) and romanVals[j] < romanVals[aromaticNum[i+2]]):
            total -= romanVals[j] * multiplier
        else:
            total += romanVals[j] * multiplier
    else:
        multiplier = int(j)

print(total)