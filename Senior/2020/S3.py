needle = input()
haystack = input()

# find counts of each letter in the needle
needle_counts = {}
for letter in needle:
    if letter in needle_counts:
        needle_counts[letter] += 1
    else:
        needle_counts[letter] = 1

results = set()

# sliding window
for i in range(len(haystack) - len(needle) + 1):
    # check if the counts are the same
    counts = {}
    for j in range(i, i + len(needle)):
        letter = haystack[j]
        if letter in counts:
            counts[letter] += 1
        else:
            if letter not in needle_counts:
                break
            counts[letter] = 1
    if counts == needle_counts:
        results.add(haystack[i:i + len(needle)])

print(len(results))