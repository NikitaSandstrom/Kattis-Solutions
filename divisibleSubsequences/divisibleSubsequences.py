import sys

numTestCases = int(input())
for i in range(numTestCases):
    divisor, length = [int(i) for i in input().split()]
    arr = [int(i) for i in sys.stdin.readline().split()]
    result = 0
    mod = []
    sum = 0
    
    for i in range(divisor + 1):
        mod.append(0)
   
    for i in range(length):
        sum = sum + arr[i]
        mod[((sum % divisor) + divisor) % divisor] = mod[((sum % divisor)+ divisor) % divisor] + 1
    
    for i in range(divisor):
        if (mod[i] > 1):
            result = result + (mod[i] * (mod[i] - 1)) // 2

    result = result + mod[0]

    print(result)