endCount = int(input(""))
infected = int(input(""))
daySpread = int(input(""))
newInfects = infected
days = 0
while infected < endCount + 1:
    days += 1
    newInfects = newInfects * daySpread
    infected += newInfects
print(days)