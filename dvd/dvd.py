import sys

numTrials = int(sys.stdin.readline().strip())

for trial in range(numTrials):
    numItems = int(sys.stdin.readline().strip())
    nums = []
    while len(nums) < numItems:
        nums += [int(i) for i in sys.stdin.readline().split()]
    sortedNums = sorted(nums)
    si = 0
    for item in nums:
        if item == sortedNums[si]:
            si += 1
    print(len(nums) - si)