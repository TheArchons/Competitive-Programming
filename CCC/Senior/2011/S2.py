lines = int(input())
chars = []
total = 0
for i in range(lines):
    chars.append(input())
for i in range(lines):
    c = input()
    if c == chars[i]:
        total += 1

print(total)

#wth how does this mle