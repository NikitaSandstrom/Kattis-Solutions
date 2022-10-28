i=int(input())
p=int(input())
m=100
for day in range(i-1):
    c=int(input())
    if c>p:
        m+=min(m//p,100000)*(c-p)
    p=c
n=('%f'%m).rstrip('0').rstrip('.')
print(n)