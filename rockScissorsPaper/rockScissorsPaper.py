def rps(i, j, ii, jj, g):
   if (i<0 or i>=r or j<0 or j >= c): return
   if (g[i][j] == 'R' and g[ii][jj] == 'S'): g[ii][jj] = 'R'
   if (g[i][j] == 'S' and g[ii][jj] == 'P'): g[ii][jj] = 'S'
   if (g[i][j] == 'P' and g[ii][jj] == 'R'): g[ii][jj] = 'P'
   return

n=int(input())
for t in [0]*n:
    r,c,d=map(int,input().split())
    g=[]
    for i in [0]*r:
        g.append(list(input()))
    
    for i in range(0,r):
        for j in range(0,c):
            rps(i,j,i+1,j,g)
            rps(i,j,i-1,j,g)
            rps(i,j,i,j+1,g)
            rps(i,j,i,j-1,g)

    print(g)