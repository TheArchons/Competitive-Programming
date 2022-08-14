from itertools import permutations

needle = input()
haystack = input()

# all permutations of the needle
allPermutations = set(permutations(needle))

permCount = 0

for needlePermutation in allPermutations:
    if "".join(needlePermutation) in haystack:
        permCount += 1
        
print(permCount)