import math
y = int(input(""))
x = int(input(""))
maxCoord = max(x, y)
ys = []
xLock = 0
yLock = 0
cVal = 0
for i in range(0, y):
    ys.append(input("").split(" "))
while yLock != y - 1 and xLock != x - 1:
    cVal = int(ys[yLock][xLock])
    cMultis = []
    for multipleVal in range(1, math.ceil(cVal/2)+1):
        if multipleVal > maxCoord:
            break
        if cVal % multipleVal == 0:
            currMultiple = int(cVal/multipleVal)
            cMultis.append([multipleVal, currMultiple])
            cMultis.append([currMultiple, multipleVal])
    if y != x:
        for currMulti, workingCoord in enumerate(cMultis):
            if workingCoord[0] > y or workingCoord[1] > x:
                cMultis.pop(currMulti)
    break

print(cMultis)
