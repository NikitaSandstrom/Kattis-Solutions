/*  Author:             Nikita Sandstrom
*   Last Updated:       10/10/2022
*   File Name:          divideBy100.cpp
*   Kattis Attempted:   Divide By 100
*/ 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int numberToDivide, numToDivideBy;
    double answer;
    cin >> numberToDivide >> numToDivideBy;

    //convert numberToDivide into a string and put into an array in reverse order
    string numberToDivideString = to_string(numberToDivide);
    reverse(numberToDivideString.begin(), numberToDivideString.end());
    char numberToDivideArray[numberToDivideString.length()];
    for (int i = 0; i < numberToDivideString.length(); i++) {
        numberToDivideArray[i] = numberToDivideString[i];
    }

    answer = numberToDivide / numToDivideBy;

    int decimalPlaces = 0;
    while (numToDivideBy != 1) {
        numToDivideBy /= 10;
        decimalPlaces++;
    }

    


}