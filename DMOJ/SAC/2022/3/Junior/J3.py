inputLen = int(input())
out = 1
for i in range(inputLen):
    temp = input()
    if temp == 'A':
        continue
    elif temp == 'B':
        out *= 0.8
    elif temp == 'C':
        out *= 0.6
    elif temp == 'D':
        out *= 0.4
    elif temp == 'E':
        out *= 0.2
print(out)