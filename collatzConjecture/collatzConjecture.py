def x(n,v):
 i=0
 while n>1:
  i+= 1
  n=3*n+1 if n&1 else n>>1
  if n not in v:
   v[n]=i
def z(n,o):
 i=0
 if n not in o:
  while n>1:
   i+=1
   n=3*n+1 if n&1 else n>>1
   if n in o:
    return n,i
 return n,i
while True:
 a,b=map(int,input().split())
 if a==0 or b==0:break
 k={a:0}
 x(a,k)
 q=z(b,k)
 n=q[0]
 c=q[1]
 print("{:d} needs {:d} steps, {:d} needs {:d} steps, they meet at {:d}".format(a,k[n],b,c,n))