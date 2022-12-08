line1 = input()
line2 = input()
occurences = {}
total = wildcards = 0
exit = False
for char in line1:
    if char in occurences:
        occurences[char] += 1
    else:
        occurences[char] = 1
    total += 1
for char in line2:
    if char == '*':
        wildcards += 1
        continue
    if char in occurences:
        occurences[char] -= 1
        if occurences[char] == 0:
            del occurences[char]
    else:
        print("N")
        exit = True
        break
    total -= 1
if not exit:
    if total == wildcards:
        print("A")
    else:
        print("N")
