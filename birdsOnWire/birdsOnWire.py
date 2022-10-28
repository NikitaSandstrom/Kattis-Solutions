import sys

l, d, n = [int(i) for i in sys.stdin.readline().split()]
birds = sorted([int(input()) for _ in range(n)])

answer = 0
currentPos = 6

for bird in birds:
    while currentPos + d <= bird:
        currentPos += d
        answer += 1
    currentPos = bird + d
while currentPos <= (l - 6):
    currentPos += d
    answer += 1

print(answer)