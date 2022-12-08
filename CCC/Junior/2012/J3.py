icon = ["*x*", " xx", "* *"]

scale = int(input())
for i in range(3):
    line = ""
    for j in icon[i]:
        line += j * scale
    for k in range(scale):
        print(line)