len = int(input())
sides = [int(x) for x in input().split()]
bottoms = [int(x) for x in input().split()]
prevHeight = sum = 0
for i in range(len+1):
    if i == 0:
        prevHeight = sides[i]
        continue
    width = bottoms[i-1]
    height = sides[i]
    sum += (min(prevHeight, height)*width)+(abs(prevHeight-height)*width)/2
    prevHeight = height
print(sum)