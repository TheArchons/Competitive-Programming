len = int(input())
input()
tree = input().split()
left, right, top, down = int(tree[1]), int(tree[1]), int(tree[0]), int(tree[0])
left = left-1
right = len-right
top = top-1
down = len-down

print(max(left, right, top, down))
