n,t=map(int,input().split())
v=list(map(int,input().split()))
v.sort()
if t==1:
 for i in range(n):
  l=0
  h=n
  while l<h:
   m=l+(h-l)//2
   if v[m]+v[i]==7777:
    print("Yes")
    exit()
   if v[m]+v[i]<7777:
    l=m+1
   else:
    h=m
 print("No")
if t==2:
 print(("Contains duplicate","Unique")[len(set(v))==n])
if t==3:
 m={}
 for i in range(n):
  if v[i] in m:
   m[v[i]]+=1
  else:
   m[v[i]]=1
 for k in m:
  if m[k]>n/2:
   print(k)
   exit()
 print(-1)
if t==4:
 if n%2:
  print(v[n//2])
 else:
  print(v[n//2-1],v[n//2])
if t==5:
 for i in range(n):
  print(("",v[i])[100<=v[i]<=999])