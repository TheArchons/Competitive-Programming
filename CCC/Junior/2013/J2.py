whitelist = {'I', 'O', 'S', 'H', 'Z', 'X', 'N'}
strIn = input()
yes = True
for char in strIn:
    if char not in whitelist:
        if yes:
            print("NO")
        yes = False
if yes:
    print("YES")