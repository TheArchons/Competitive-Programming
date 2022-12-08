def createCounts():
    letters = 'abcdefghijklmnopqrstuvwxyz'
    return {letter: 0 for letter in letters}

needle = input()
haystack = input()

needleLen = len(needle)
haystackLen = len(haystack)

# if the length of needle is longer than haystack, print 0
if needleLen > haystackLen:
    print(0)
else:
    # find counts of each letter in the needle
    needle_counts = createCounts()
    for letter in needle:
        needle_counts[letter] += 1

    results = set()
    counts = createCounts()

    for i in range(needleLen):
        counts[haystack[i]] += 1

    if counts == needle_counts:
        results.add(hash(haystack[0:needleLen]))

    counts[haystack[0]] -= 1

    count = 0

    # sliding window
    for i in range(1, haystackLen - needleLen + 1):
        counts[haystack[i+needleLen-1]] += 1
        if counts == needle_counts:
            results.add(hash(haystack[i:i+needleLen]))
        counts[haystack[i]] -= 1

    print(len(results))