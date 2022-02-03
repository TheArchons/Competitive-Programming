humidity = int(input())
maxHours = int(input())
hour = 0
altitude = 100

while (maxHours >= hour and altitude > 0):
    hour += 1
    altitude = (-6*(hour**4)) + (humidity*(hour**3) + (2*(hour**2)) + hour)

if altitude <= 0:
    print("The ballon first touches the ground at hour:")
    print(hour-1)
else:
    print("The balloon does not touch ground in the given time.")