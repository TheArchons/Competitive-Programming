walk = 0
speed = int(input().split()[1])
sections = input()
if speed == 0:
    walking = True
else:
    walking = False
for i in sections:
    if walking:
        if (i == 'D'):
            walking = False
            speed = 1
        else:
            walk += 1
        continue
    if (i == 'F'):
        continue
    elif (i == 'D'):
        speed += 1
    else:
        speed -= 1
        if (speed <= 0):
            walking = True
            walk += 1
        
print(walk)