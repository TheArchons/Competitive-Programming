line1 = input().split()
taskNum = int(line1[0])
checks = int(line1[1])


tasks = []
for i in range(taskNum):
    task = input().split()
    tasks.append((int(task[0]), task[1]))


prevCheck = 0
for i in range(checks):
    checkTime = int(input())
    for task in tasks:
        if task[0] <= checkTime and task[0] > prevCheck:
            print(task[1])
    prevCheck = checkTime
#print(tasks)