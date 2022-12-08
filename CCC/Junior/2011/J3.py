prevPrevNum = int(input())
prevNum = int(input())
curr = 0
steps = 2
while (prevNum <= prevPrevNum):
    temp = prevPrevNum
    prevPrevNum = prevNum
    prevNum = temp - prevNum
    steps += 1

print(steps)