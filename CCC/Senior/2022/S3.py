import math

def goodSampleCount(notes, requiredCount):
    count = 0
    for t in range(len(notes)):
        if t >= len(notes) - 1 or notes[t] == notes[t+1]:
            count += 1
        else:
            count += 2
    if count == requiredCount:
        return True
    else:
        return False

temp = input().split()
temp = [int(x) for x in temp]

notes = temp[0]
maxPitch = temp[1]
reqSamples = temp[2]

goodSamples = notes
ones = notes
loopSubtract = 1

while goodSamples < reqSamples and ones > 0:
    ones -= 1
    goodSamples += loopSubtract
    loopSubtract += 1

if ones <= 0 or reqSamples < notes:
    print("-1")
else:
    outputArr = [1]*ones
    for i in range(ones+1, notes+1):
        outputArr.append(i)

    outputArr[-(goodSamples-reqSamples)] = 1
    # print outputArr space separated
    for i in range(len(outputArr)):
        print(outputArr[i], end=" ")

