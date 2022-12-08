rolls = int(input())
p1 = p2 = 100
for i in range(rolls):
    roll = input().split()
    if int(roll[0]) > int(roll[1]):
        p2 -= int(roll[0])
    elif int(roll[0]) < int(roll[1]):
        p1 -= int(roll[1])
print(p1)
print(p2)