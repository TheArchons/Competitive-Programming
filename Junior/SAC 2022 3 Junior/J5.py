temp = input().split(' ')
conversions = int(temp[0])
binaryLen = int(temp[1])
binaryIn = input()
conversionDict = {}
conversionLens = []
conversionArr = []
output = ""
for i in range(conversions):
    temp = input().split(' ')
    conversionDict[temp[1]] = temp[0]
    conversionLens.append(len(temp[1]))
    conversionArr.append(temp[1])
conversionLens = sorted(conversionLens, reverse=True)
conversionArr = sorted(conversionArr, reverse=True)
breakOut = False
while len(binaryIn) != 0:
    for i in conversionArr:
        temp = binaryIn[:len(i)]
        if temp == i:
            output += conversionDict[i]
            if len(binaryIn) == len(i):
                breakOut = True
                break
            binaryIn = str(binaryIn)[len(i):]
            break
    if breakOut:
        break  
print(output)