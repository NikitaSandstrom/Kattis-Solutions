import math
for i in range(int(input())):
 a,b,d=map(int,input().split())
 print(('no','yes')[d%math.gcd(a,b)==0])