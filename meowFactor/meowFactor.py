import sys
import math

n = int(sys.stdin.readline())
m = int(math.pow(n, 1.0/9))+1
meow_fact = 1
for i in range(2,m+1):
    if (n % i**9) == 0:
        meow_fact = i
print(meow_fact)