
data = [int(x) for x in input().split()]
while data[0] != 0:
    b = data[0]
    p = data[1]
    m = data[2]

    p = int(str(p), b)
    m = int(str(m), b)

    k = p % m
    if k == 0:
        print("0")
    else:
        digits = []
        while k:
            digits.append(k % b)
            k = k // b
        digits = digits[::-1]
        print(''.join(map(str, digits)))
    data = [int(x) for x in input().split()]