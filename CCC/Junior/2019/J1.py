import math
apples = 0
bananas = 0
for i in reversed(range(3)):
    apples += int(input())*i
for i in reversed(range(3)):
    bananas = int(input())*i
if apples < bananas:
    print("A")
elif apples > bananas:
    print("B")
else:
    print("T")