prev = 0
numArr = []
for i in range(4):
    numArr.append(int(input()))


type = ""
noFish = False
for i in range(1, 4):
    if i == 1:
        if numArr[i] > numArr[i-1]:
            type = "Fish Rising"
        elif numArr[i] < numArr[i-1]:
            type = "Fish Diving"
        else:
            type = "Fish At Constant Depth"
    else:
        if type == "Fish Rising":
            if numArr[i] <= numArr[i-1]:
                print("No Fish")
                noFish = True
                break
        elif type == "Fish Diving":
            if numArr[i] >= numArr[i-1]: 
                print("No Fish")
                noFish = True
                break
        elif type == "Fish At Constant Depth":
            if numArr[i] != numArr[i-1]:
                print("No Fish")
                noFish = True
                break

if (not noFish):
    print(type)
