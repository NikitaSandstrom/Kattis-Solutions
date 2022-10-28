import sys

numTrials = int(sys.stdin.readline().strip())

for trial in range(numTrials):
    k, numItems = [int(i) for i in sys.stdin.readline().split()]
    nums = []
    while len(nums) < numItems:
        nums += [int(i) for i in sys.stdin.readline().split()]
    sortedNums = sorted(nums)
    si = 0
    for item in nums:
        if item == sortedNums[si]:
            si += 1
    print("{0} {1}".format(k, len(nums) - si))