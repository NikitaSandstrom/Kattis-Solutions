import math
for i in [0]*int(input()):
    n,m=map(int,input().split())
    print(math.comb(n,m-1))