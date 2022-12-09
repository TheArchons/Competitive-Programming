n = int(input())
sums = 0

fives = n//5
for i in range(fives+1):
    if (n-(i*5))%4 == 0:
        sums += 1
print(sums)
