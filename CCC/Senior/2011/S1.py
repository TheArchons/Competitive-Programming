ts = ss = 0
for i in range(int(input())):
    for c in input():
        if c == 'S' or c == 's':
            ss += 1
        elif c == 'T' or c == 't':
            ts += 1
print("English" if ts > ss else "French")