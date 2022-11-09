import sys
import math

def is_prime(n):
  for i in range(2,int(math.sqrt(n))+1):
    if (n%i) == 0:
      return False
  return True

while True:
    p, a = [int(i) for i in sys.stdin.readline().split()]

    if p == 0 and a == 0:
        break

    if is_prime(p):
        if(pow(a,p,p) == a):
            print("yes")
        else:
            print("no")
    else:
        print("no")
