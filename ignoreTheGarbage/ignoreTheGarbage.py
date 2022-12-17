# 1 2 5 9 8 6 0
dict = {1:"1", 2:"2", 3:"5", 4:"9", 5:"8", 6:"6", 7:"01", 8:"11", 9:"21", 10:"51", 11:"91", 12:"81", 13:"61", 14:"02", 49:"001", 343:"0001"}

while True:
    k = int(input())
    stringBuilder = ""
    
    c = k // 343
    if c > 0:
        stringBuilder = stringBuilder + dict[c]

    print(stringBuilder)
