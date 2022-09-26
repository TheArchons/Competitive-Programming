prevDir = []
Rs = 0
Cs = 0
y = int(input(""))
x = int(input(""))
dirInp = int(input(""))
for i in range(dirInp):
    dir = input("")
    if dir in prevDir:
        prevDir.remove(dir)
        if dir[0] == "R":
            Rs -= 1
        else:
            Cs -= 1
    else:
        prevDir.append(dir)
        if dir[0] == "R":
            Rs += 1
        else:
            Cs += 1
total = x-Cs
total = Rs * total
temp = y-Rs
temp = Cs * temp
total += temp
print(total)