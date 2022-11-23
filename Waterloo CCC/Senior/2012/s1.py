goalJersey = int(input())
combinations = 0

for i in range(goalJersey-3):
    for j in range(i+1, goalJersey-2):
        for k in range(j+1, goalJersey-1):
            combinations += 1

print(combinations)