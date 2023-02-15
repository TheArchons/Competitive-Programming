def isPrime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

ins = input()
ins = ins.split()
d = int(ins[0])
n = int(ins[1])
num = max(int((10**(d*2))/10), n)
while(not isPrime(num)):
    num += 1
print(num)