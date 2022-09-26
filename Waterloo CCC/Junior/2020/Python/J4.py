import copy

mStr = list(input(""))
cStr = list(input(""))
currPos1 = 0
currPos2 = len(cStr) - 1
cShifts = []
tempShift = copy.deepcopy(cStr)
for shift in range(len(cStr)):
    cShifts.append(copy.deepcopy(tempShift))
    temp = tempShift[-1]
    tempShift.pop()
    tempShift = [temp] + tempShift
while currPos2 < len(mStr):
    if mStr[currPos1:currPos2+1] in cShifts:
        print("yes")
        break
    currPos1 += 1
    currPos2 += 1
else:
    print("no")