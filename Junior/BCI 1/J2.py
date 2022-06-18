import math

n = int(input())
ingredients = input().split()
total = 0

for ingredient in ingredients:
    total = math.gcd(total, int(ingredient))

for ingredient in ingredients:
    ingredient = int(ingredient)/total
    print(int(ingredient), end=' ')