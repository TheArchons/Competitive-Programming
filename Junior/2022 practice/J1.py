x = int(input())
y = 0
count = 0
while y <= x:
    if x <= 5 and y <= 5:
        count += 1
    y += 1
    x -= 1
print(count)