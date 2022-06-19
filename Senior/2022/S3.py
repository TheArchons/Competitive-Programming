import itertools

def goodSampleCount(notes, requiredCount):
    count = 0
    for t in range(len(notes)):
        seen = set()
        for i in range(t, len(notes)):
            if notes[i] in seen:
                break
            count += 1
            seen.add(notes[i])
    if count == requiredCount:
        return True
    else:
        return False

temp = input().split()
temp = [int(x) for x in temp]

notes = temp[0]
maxPitch = temp[1]
goodSamples = temp[2]

notePosses = itertools.product(range(1, maxPitch + 1), repeat=notes)

didBreak = False
for i in notePosses:
    if goodSampleCount(i, goodSamples):
        for j in range(notes):
            if j == notes-1:
                print(i[j])
            else:
                print(i[j], end=' ')
        didBreak = True
        break

if not didBreak:
    print('-1')