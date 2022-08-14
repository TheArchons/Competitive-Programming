from itertools import permutations

needle = input()
haystack = input()

# all permutations of the needle
allPermutations = set(permutations(needle))

permCount = 0

# sliding window of the haystack
for i in range(len(haystack) - len(needle) + 1):
    window = tuple(haystack[i:i+len(needle)])
    if window in allPermutations:
        permCount += 1
        allPermutations.remove(window)
        
print(permCount)