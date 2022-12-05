import re

x = 0
directions = []
while True:
    x = input("")
    if x == "99999":
        break
    numbers = [int(i) for i in x]
    direction = int(numbers[0] + numbers[1])
    if direction % 2 != 0:
        directions.append("left" + " " + str(numbers[2]) + str(numbers[3]) + str(numbers[4]))
    elif direction == 0:
        directions.append(re.sub('[0-9]', '', directions[-1]) + str(numbers[2]) + str(numbers[3]) + str(numbers[4]))
    else:
        directions.append("right" + " " + str(numbers[2]) + str(numbers[3]) + str(numbers[4]))
for direction in directions:
    print(direction)