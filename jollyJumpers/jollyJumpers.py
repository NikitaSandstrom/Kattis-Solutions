a = list(map(int,input().split()))
val = a[0] - 1


for i in range(1, len(a) - 1):
    if (abs(a[i] - a[i+1]) != val):
        print("Not jolly")
        exit()
    val -= 1
print("Jolly")