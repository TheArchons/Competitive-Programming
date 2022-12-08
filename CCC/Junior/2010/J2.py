nikkyForward = int(input())
nikkyBackward = int(input())
ByronForward = int(input())
ByronBackward = int(input())
stepCount = int(input())

#find nicky's position
nikkyPos = 0
currSteps = 0
isForward = True
for i in range(stepCount):
    if isForward:
        if currSteps == nikkyForward:
            isForward = False
            currSteps = 1
            nikkyPos -= 1
        else:
            currSteps += 1
            nikkyPos += 1
    else:
        if currSteps == nikkyBackward:
            isForward = True
            currSteps = 1
            nikkyPos += 1
        else:
            currSteps += 1
            nikkyPos -= 1

#find byron's position
byronPos = 0
currSteps = 0
isForward = True
for i in range(stepCount):
    if isForward:
        if currSteps == ByronForward:
            isForward = False
            currSteps = 1
            byronPos -= 1
        else:
            currSteps += 1
            byronPos += 1
    else:
        if currSteps == ByronBackward:
            isForward = True
            currSteps = 1
            byronPos += 1
        else:
            currSteps += 1
            byronPos -= 1

if nikkyPos == byronPos:
    print("Tied")
elif nikkyPos > byronPos:
    print("Nikky")
else:
    print("Byron")