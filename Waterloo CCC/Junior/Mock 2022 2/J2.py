ins = input().split()
lines = int(ins[0])
andrew = int(ins[1])
tommy = int(ins[2])
andrewTotal = tommyTotal = 0
for i in range(lines):
    ins = input().split()
    if int(ins[0]) < andrew:
        andrewTotal += 1
    else:
        andrewTotal += 2
    if int(ins[1]) < tommy:
        tommyTotal += 1
    else:
        tommyTotal += 2

if andrewTotal < tommyTotal:
    print("Andrew wins!")
elif andrewTotal > tommyTotal:
    print("Tommy wins!")
else:
    print("Tie!")
    