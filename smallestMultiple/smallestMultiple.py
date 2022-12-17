import functools

def gcd(a, b):
	if b > a:
		a, b = b, a
	while b != 0:
		a, b = b, a % b
	return a

def lcm(a, b):
	return (a*b)//gcd(a, b)

while True:
    try:
        arr = list(map(int, input().split()))
        print(int(functools.reduce(lcm,arr[1:],arr[0])))
    except EOFError:
        break