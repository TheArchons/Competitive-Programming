maxBid = 0
maxBidder = ""

for x in range(int(input())):
    bidder = input()
    bid = int(input())
    if bid > maxBid:
        maxBidder = bidder
        maxBid = bid

print(maxBidder)
