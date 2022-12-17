import math
while True:
    try:
        dict = {}
        n = input()
        for char in n:
            dict[char] = dict.get(char, 0) + 1
        result = math.factorial(len(n))
        for k, v in dict.items():
            result = result // math.factorial(v)
        print(result)
    except EOFError:
        break