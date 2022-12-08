def distinctDigits(n):
    n = str(n)
    seen = {-1}
    for i in range(len(n)):
        if n[i] not in seen:
            seen.add(n[i])
        else:
            return False
    return True

year = int(input(""))
year += 1
while(not distinctDigits(year)):
    year += 1
print(year)
