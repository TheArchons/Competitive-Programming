line1 = input().split()
matrixSize = int(line1[0])
matrix = []
queryNum = int(line1[1])
sprinkles = 0

for i in range(queryNum):
    query = input().split()
    if int(query[0]) == 1:
        #for query1
        x = int(query[1])
        y = int(query[2])
        matrix.append((x,y))
    else:
        #for query2
        startX = int(query[1])
        startY = int(query[2])
        endX = int(query[3])
        endY = int(query[4])
        for p in matrix:
            if p[0] >= startX and p[0] <= endX and p[1] >= startY and p[1] <= endY:
                sprinkles += 1

print(sprinkles)