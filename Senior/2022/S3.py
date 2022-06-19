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
goodSamples = temp[2]

outputArr = [1]*notes
requiredDiffs = goodSamples-notes
didBreak = False

if notes <= requiredDiffs or notes > goodSamples:
    print('-1')
else:
    if requiredDiffs % 2 == 0:
        for i in range(1, int(requiredDiffs/2)*2, 2):
            outputArr[i] = 2
    else:
        for i in range(0, math.ceil(requiredDiffs/2)*2, 2):
            outputArr[i] = 2

    for i in range(len(outputArr)):
        print(outputArr[i], end=" ")

"""Twos = math.floor((goodSamples-notes)/2)
Ones = notes-Twos
didBreak = False
while Ones >=0 and Twos <= Ones:
    notePosses = itertools.permutations([1]*Ones + [2]*Twos, notes)
    for i in notePosses:
        if goodSampleCount(i, goodSamples):
            for j in range(notes):
                if j == notes-1:
                    print(i[j])
                else:
                    print(i[j], end=' ')
            didBreak = True
            break
    if didBreak:
        break
    Ones -= 1
    Twos += 1

if not didBreak:
    print('-1')"""