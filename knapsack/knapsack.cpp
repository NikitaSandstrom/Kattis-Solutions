/*  Author:             Nikita Sandstrom
*   Last Updated:       --/--/2021
*   File Name:          knapsack.cpp
*   Kattis Attempted:   Knapsack
*/ 

#include <iostream>

using namespace std;

int main() {
    int ksWeight, objectsInPlay;
    cin >> ksWeight >> objectsInPlay;

    int itemsOut[objectsInPlay][2];
    //Change whole thing to be while(cin) as we have to take a lot of test cases in.
    for(int i = 0; i < objectsInPlay; i++) {
        int itemValue, itemWeight;
        cin >> itemValue >> itemWeight;
        itemsOut[i][0] = itemValue;
        itemsOut[i][1] = itemWeight;
    }
}