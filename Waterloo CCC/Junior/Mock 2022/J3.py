input()
s1 = input()
s2 = input()
s1Occurs = dict()
total = max = 0
for c in s1:
    if s1Occurs.get(c) != None:
        s1Occurs[c] += 1
    else:
        s1Occurs[c] = 1
    if s1Occurs[c] > max:
        s1Occurs = max
minShares = 1000000
for c in s2:
    if s1Occurs.get(c) != None:
        total += s1Occurs[c]
        if s1Occurs[c] < minShares:
            minShares = s1Occurs[c]
    else:
        minShares = 0


if (max < minShares):
    total += minShares-max
print(total)