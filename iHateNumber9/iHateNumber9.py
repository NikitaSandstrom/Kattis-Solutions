testCases = int(input())
for testCase in range(testCases):
    k = int(input())
    print(8 * pow(9, k - 1, 1000000007) % 1000000007)