import math
for _ in [0]*int(input()):
    i=int(input())
    print(int(math.comb(2*i,i)//(i+1)))