pairs = int(input())

students = input().split()
students = [int(student) for student in students]
students.sort()
total = 0

for i in range(0, len(students), 2):
    total += students[i+1] - students[i]

print(total)