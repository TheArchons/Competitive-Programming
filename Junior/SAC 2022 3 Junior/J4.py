def convertToBinary(number, base):
    #convert number to binary
    end = number
    temp = "-1"
    number = list(str(number))
    number = [int(i) for i in number]
    binary = [0]
    #list to int
    

    while (int(temp) != end):
        temp = ""
        for i in binary:
            temp += str(i)
        for pos, i in enumerate(reversed(binary)):
            binary[pos] += 1
            if i == 2:
                binary[pos] = 0
                binary[pos+1] += 1
                break
        if len(temp) == 0:
            temp = "-1"
    return number


def baseConversion(base1, number, base2):
    #convert number to binary
    print(pow(base1, number))

inputLen = int(input())
for i in range(inputLen):
    temp = input().split(' ')

    print(baseConversion(int(temp[0]), int(temp[1]), int(temp[2])))