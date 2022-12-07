prices = input().split()
seats = input().split()
total = (int(prices[0])*int(seats[0])) + (int(prices[1])*int(seats[1])) + (int(prices[2])*int(seats[2]))
people = 0
for i in seats:
    people += int(i)
print(people, end=" ")
print(total)