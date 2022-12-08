sameGroup = {}
sameGroups = int(input())

for i in range(sameGroups):
    pair = input().split()
    if pair[0] not in sameGroup:
        sameGroup[pair[0]] = set()
    sameGroup[pair[0]].add(pair[1])

diffGroup = {}
diffGroups = int(input())

for i in range(diffGroups):
    pair = input().split()
    if pair[0] not in diffGroup:
        diffGroup[pair[0]] = set()
    diffGroup[pair[0]].add(pair[1])

violations = 0
groups = int(input())
for group in range(groups):
    groupMembers = input().split()
    for i in range(3):
        if groupMembers[i] in sameGroup:
            for member in sameGroup[groupMembers[i]]:
                if not member in groupMembers:
                    violations += 1
        if groupMembers[i] in diffGroup:
            for member in diffGroup[groupMembers[i]]:
                if member in groupMembers:
                    violations += 1

print(violations)