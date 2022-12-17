import math
n,k=map(int,input().split())
a=0
while n>0:
 n-=math.ceil(float(n)/k)
 a+=1
print(a+1)