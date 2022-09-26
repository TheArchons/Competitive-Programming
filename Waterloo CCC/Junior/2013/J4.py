time = int(input(""))
choresCount = int(input(""))
chores = []
for i in range(choresCount):
    chores.append(int(input("")))
chores.sort()
index = -1
while (time >= 0):
    index += 1
    time -= chores[index]
print(index)