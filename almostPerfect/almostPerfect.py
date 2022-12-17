import math
while True:
    try:
        n = int(input())
        divisors = []
        sum = 1
        for i in range (2,int(math.sqrt(n)) + 1):
            if(n % i == 0):
                sum += i
                if(i*i != n):
                    sum += n // i
        m = str(n)
        if sum == n:
            print(m + " perfect")
        elif sum <= n + 2 and sum >= n - 2:
            print(m + " almost perfect")
        else:
            print(m + " not perfect")
    except EOFError:
        break