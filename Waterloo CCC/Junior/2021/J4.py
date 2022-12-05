def code():
    books = input("")
    emptyCount = 0
    if len(books) <= 1:
        print(0)
        return
    lCount = books.count("L")
    mCount = books.count("M")
    sCount = books.count("S")
    if lCount == 0:
        emptyCount += 1
    if mCount == 0:
        emptyCount += 1
    if sCount == 0:
        emptyCount += 1
    if emptyCount > 1:
        print(0)
        return
    if lCount == 0:
        lCount = mCount
        lMSwapped = True
    elif mCount == 0:
        mCount = lCount
        mLSwapped = True
    misM = 0
    misL = 0
    misS = 0
    for l in range(lCount-1):
        if l >= len(books) -1:
            break
        if books[l] == "M":
            misM += 1
    for m in range(lCount, lCount + mCount -1):
        if m >= len(books) -1:
            break
        if books[m] == "L":
            misL += 1
    for s in range(lCount + mCount, len(books)-1):
        if s >= len(books) -1:
            break
        if books[s] != "M":
            misS += 1
    print(misM+misL+misS-min(misM, misL))
code()