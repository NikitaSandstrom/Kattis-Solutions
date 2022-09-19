/*  Author:             Nikita Sandstrom
*   Last Updated:       19/09/2022
*   File Name:          basicProgramming1.cpp
*   Kattis Attempted:   Basic Programming 1
*/ 

#include <iostream>

using namespace std;

int main() {
    int numbers, testCase;

    cin >> numbers >> testCase;

    int numbersArray[numbers];

    for (int i = 0; i < numbers; i++) {
        int numInput;
        cin >> numInput;
        numbersArray[i] = numInput;
    }
    
    if (testCase == 1) {
        cout << "7" << endl;
    } else if (testCase == 2) {
        if (numbersArray[0] > numbersArray[1]) {
            cout << "Bigger" << endl;
        } else if (numbersArray[0] < numbersArray[1]) {
            cout << "Smaller" << endl;
        } else {
            cout << "Equal" << endl;
        }
    } else if (testCase == 3) {
        // create new array with the first three indicies of the numbersArray
        // sort the new array
        // print the median

        int newArray[3];
        newArray[0] = numbersArray[0];
        newArray[1] = numbersArray[1];
        newArray[2] = numbersArray[2];

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (newArray[i] > newArray[j]) {
                    int temp = newArray[i];
                    newArray[i] = newArray[j];
                    newArray[j] = temp;
                }
            }
        }

        cout << newArray[1] << endl;
    } else if (testCase == 4) {
        // print the sum of the array
        long sum = 0;
        for (int i = 0; i < numbers; i++) {
            sum += numbersArray[i];
        }
        cout << sum << endl;
    } else if (testCase == 5) {
        // print the sum of all integers of the array that are even
        long sum = 0;
        for (int i = 0; i < numbers; i++) {
            if (numbersArray[i] % 2 == 0) {
                sum += numbersArray[i];
            }
        }
        cout << sum << endl;
    } else if (testCase == 6) {
        // Map all the numbers in numbersArray to a letter of the alphabet with modulo 26
        // Print the letters
        for (int i = 0; i < numbers; i++) {
            int num = numbersArray[i];
            char letter = 'a' + (num % 26);
            cout << letter;
        }
        cout << endl;
    } else if (testCase == 7) {
        // Keep track of the indicies that have been visited
        // If an index is visited twice, print "Cyclic" and stop
        // If the current index i is the last index of the array, print "Done" and stop
        // Else, repeat
        // If the current index i is out the valid bound of the array, print "Out" and stop

        int visitedIndicies[numbers] = {0};
        int i = 0;

        while (true) {
            if (i >= numbers) {
                cout << "Out" << endl;
                break;
            } else if (visitedIndicies[i] == 1) {
                cout << "Cyclic" << endl;
                break;
            } else if (i == numbers - 1) {
                cout << "Done" << endl;
                break;
            } else {
                visitedIndicies[i] = 1;
                i = numbersArray[i];
            }
        }
    }
    
    return 0;
}