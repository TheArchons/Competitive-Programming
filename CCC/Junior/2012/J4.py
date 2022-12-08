alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

shift = int(input())
strIn = input()
for pos, c in enumerate(strIn):
    charPos = alphabet.find(c)
    shiftVal = charPos - ((3*(pos+1)) + shift)
    if shiftVal < 0:
        shiftVal += 26
    print(alphabet[shiftVal], end="")
