def createCounts():
    letters = 'abcdefghijklmnopqrstuvwxyz'
    return {letter: 0 for letter in letters}

needle = input()
haystack = input()

# if the length of needle is longer than haystack, print 0
if len(needle) > len(haystack):
    print(0)
else:
    # find counts of each letter in the needle
    needle_counts = createCounts()
    for letter in needle:
        needle_counts[letter] += 1

    results = set()
    counts = createCounts()

    for i in range(len(needle)):
        counts[haystack[i]] += 1

    if counts == needle_counts:
        results.add(hash(haystack[0:len(needle)]))

    counts[haystack[0]] -= 1

    count = 0

    # sliding window
    for i in range(1, len(haystack) - len(needle) + 1):
        counts[haystack[i+len(needle)-1]] += 1
        if counts == needle_counts:
            results.add(hash(haystack[i:i+len(needle)]))
        counts[haystack[i]] -= 1

    print(len(results))