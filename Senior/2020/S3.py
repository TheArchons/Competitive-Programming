needle = input()
haystack = input()

results = set()

# sliding window
for i in range(len(haystack) - len(needle) + 1):
    start = 0
    find = needle.find(haystack[i])
    
    while find != -1:
        # check if the haystack is a permutation
        broke = False
        for j in range(len(needle)):
            needleVal = find+j
            if needleVal > len(needle)-1:
                needleVal -= len(needle)
            if needle[needleVal] != haystack[i + j]:
                broke = True
                break
        if not broke:
            results.add(haystack[i:i + len(needle)])
            break
        start = find + 1
        find = needle.find(haystack[i], start)
    

print(len(results))