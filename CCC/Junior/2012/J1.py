speedLimit = int(input(""))
carSpeed = int(input(""))
if (carSpeed <= speedLimit):
    print("Congratulations, you are within the speed limit!")
elif carSpeed-speedLimit <= 20:
    print("You are speeding and your fine is $100.")
elif carSpeed-speedLimit <= 30:
    print("You are speeding and your fine is $270.")
else:
    print("You are speeding and your fine is $500.")