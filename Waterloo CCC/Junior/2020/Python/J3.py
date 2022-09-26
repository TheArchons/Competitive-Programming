x = []
y = []
for inputs in range(int(input(""))):
    currIn = input("").split(",")
    x.append(int(currIn[0]))
    y.append(int(currIn[1]))
print(str(min(x)-1) + "," + str(min(y)-1))
print(str(max(x)+1) + "," + str(max(y)+1))