#brute force
"""n = int(input())
sums = 0

stack = [[0,0]]
seen = set()
while len(stack) > 0:
    four,five = stack.pop()
    #ignore if we've seen this before
    if (four,five) in seen:
        continue
    seen.add((four, five))
    sum = four*4 + five*5

    if sum < n:
        stack.append([four+1,five])
        stack.append([four,five+1])
    elif sum == n:
        sums += 1
    elif sum > n:
        continue
print(sums)"""

# solution 2
n = int(input())
sums = 0

stack = [[0,n//5]]
seen = set()
while len(stack) > 0:
    four,five = stack.pop()
    #ignore if we've seen this before
    if (four,five) in seen:
        continue
    seen.add((four, five))
    sum = four*4 + five*5
    if sum < n:
        stack.append([four+1,five])
        if five > 0:
            stack.append([four+1,five-1])
    elif sum == n:
        sums += 1
        #print(four,five)
        if five > 0:
            stack.append([four+1,five-1])

print(sums)