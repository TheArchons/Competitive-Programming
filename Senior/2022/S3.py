def goodSampleCount(notes, requiredCount):
    count = 0
    for t in range(len(notes)):
        seen = set()
        for i in range(len(notes) - t):
            if notes[i] in seen:
                break
            print(notes[i+t])
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

notePosses = []
queue = [[1], [2]]
while len(queue[0]) <= notes:
    front = queue.pop(0)
    queue.append(front + [1])
    queue.append(front + [2])
    if len(front) == notes:
        notePosses.append(front)

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
    print(-1)