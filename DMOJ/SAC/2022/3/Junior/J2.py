p1 = input().split(' ')
x1 = int(p1[0])
y1 = int(p1[1])
p2 = input().split(' ')
x2 = int(p2[0])
y2 = int(p2[1])

if x1 == x2:
    print('y-axis')
elif y1 == y2:
    print('x-axis')
else:
    print('neither')