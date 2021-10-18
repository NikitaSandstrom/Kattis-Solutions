#   Author:             Nikita Sandstrom
#   Last Updated:       16/10/2021
#   File Name:          cakey.py
#   Kattis Attempted:   Cakey McCakeFace
# 

def main():
    #Inputs values into variables or lists
    inputInVal = int(input())
    inputOutVal = int(input())
    inputInArr = list(map(int,input().split())) #splits input by space, mapping each value to integer
    inputOutArr = list(map(int,input().split()))

    #List for the values
    values = []

    #Iterates through the list, appending non-negative results into the values list
    for i in range(inputInVal):
        for j in range(inputOutVal):
            if (inputOutArr[j] - inputInArr[i] >= 0):
                values.append(inputOutArr[j] - inputInArr[i])

    #finds the mode of the values list, where min element is prioritized over max element. Code referenced off 3rd Party Website
    print(max(set(values), key = values.count))

if __name__ == "__main__":
    main()