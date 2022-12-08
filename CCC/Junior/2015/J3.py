import math
input = input()
closest = math.inf
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".lower()
for i in range(len(input)):
    if input[i] != 'a' and input[i] != 'e' and input[i] != 'i' and input[i] != 'o' and input[i] != 'u':
        for loc, char in enumerate(alphabet):
            if char == 'a' or char == 'e' or char == 'i' or char == 'o' or char == 'u':
                temp = abs(loc- alphabet.index(input[i]))
                if temp < closest:
                    closest = temp
                    closestCharLoc = loc
        if alphabet.index(input[i]) >= 25:
            nextAlph = "z"
        else:
            nextAlph = alphabet[alphabet.index(input[i]) + 1]
            if nextAlph == 'a' or nextAlph == 'e' or nextAlph == 'i' or nextAlph == 'o' or nextAlph == 'u':
                nextAlph = alphabet[alphabet.index(input[i]) + 2]
        print(input[i] + alphabet[closestCharLoc] + nextAlph, end="")
        closest = math.inf
        nextAlph = ""
    else:
        print(input[i], end="")