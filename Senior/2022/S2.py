sameGroup = {}
sameGroups = int(input())

for i in range(sameGroups):
    pair = input().split()
    sameGroup[pair[0]] = pair[1]
    sameGroup[pair[1]] = pair[0]

diffGroup = {}
diffGroups = int(input())

for i in range(diffGroups):
    pair = input().split()
    diffGroup[pair[0]] = pair[1]
    diffGroup[pair[1]] = pair[0]

violations = 0
groups = int(input())
for group in range(groups):
    groupMembers = input().split()
    for i in range(3):
        if groupMembers[i] in sameGroup:
            if not sameGroup[groupMembers[i]] in groupMembers:
                sameGroup.pop(sameGroup[groupMembers[i]])
                violations += 1
        if groupMembers[i] in diffGroup:
            if diffGroup[groupMembers[i]] in groupMembers:
                diffGroup.pop(diffGroup[groupMembers[i]])
                violations += 1

print(violations)