import math

ins = input().split()
L = int(ins[0])
H = int(ins[1])
W = int(ins[2])
diameter = int(input())

print((L*H*W)-(math.pi*((diameter/2)**2)*H))