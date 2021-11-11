highestBid = 0
for x in range(int(input(""))):
    bidder = input("")
    bid = int(input(""))
    if bid > highestBid:
        highestBidder = bidder
        highestBid = bid
print(highestBidder)