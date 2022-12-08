def isChord(chord):
    if chord in "ABCDEFGHIJKLMNOPQRST":
        return True
    else:
        return False

instructions = input()
chords = ""
scanInt = False

for c in instructions:
    if isChord(c):
        if scanInt:
            print(chords)
            chords = ""
        scanInt = False
        chords += c
    elif scanInt:
        chords += c
    elif c == '+' or c == '-':
        print(chords, end = " ")
        chords = ""
        if c == '+':
            print("tighten", end=" ")
        else:
            print("loosen", end=" ")
    else:
        scanInt = True
        chords += c

print(chords)