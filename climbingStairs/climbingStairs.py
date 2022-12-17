n,r,k=map(int,input().split())
if k>=r:
 print((n+r+(n-2*k+r)%2,k*2)[k*2-r>=n])
else:
 print((n+r+(n-r)%2,r*2)[r>=n])