/*  Author:             Nikita Sandstrom
*   Last Updated:       19/09/2022
*   File Name:          basicProgramming2.cpp
*   Kattis Attempted:   Basic Programming 2
*/ 

#include <iostream>
#include <map>

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
        // search for two values in numbersArray that are not equal to each other and add up 7777
        for (int i = 0; i < numbers; i++) {
            for (int j = i + 1; j < numbers; j++) {
                if (numbersArray[i] != numbersArray[j]) {
                    if (numbersArray[i] + numbersArray[j] == 7777) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }

        cout << "No" << endl;
    } else if (testCase == 2) {
        //Print True if all numbers in the array are distinct, otherwise print False

        for (int i = 0; i < numbers; i++) {
            for (int j = i + 1; j < numbers; j++) {
                if (numbersArray[i] == numbersArray[j]) {
                    cout << "Contains duplicate" << endl;
                    break;
                }
            }
        }

        cout << "Unique" << endl;
    } else if (testCase == 3) {
        // Create a map of key value pairs where the key is the number and the value is the number of times it appears in the array
        // Print the key that shows up numbers/2 times

        map<int, int> numberMap;

        for (int i = 0; i < numbers; i++) {
            if (numberMap.find(numbersArray[i]) == numberMap.end()) {
                numberMap[numbersArray[i]] = 1;
            } else {
                numberMap[numbersArray[i]]++;
            }
        }

        for (auto i = numberMap.begin(); i != numberMap.end(); i++) {
            if (i->second > numbers / 2) {
                cout << i->first << endl;
                break;
            } else {
                cout << -1 << endl;
            }
        }
    } else if (testCase == 4) {
        // if numbers is odd, print out the sorted median
        // if numbers is even, print out the 2 middle numbers of the sorted array

        if (numbers % 2 == 1) {
            for (int i = 0; i < numbers; i++) {
                for (int j = i + 1; j < numbers; j++) {
                    if (numbersArray[i] > numbersArray[j]) {
                        int temp = numbersArray[i];
                        numbersArray[i] = numbersArray[j];
                        numbersArray[j] = temp;
                    }
                }
            }

            cout << numbersArray[numbers / 2] << endl;
        } else {
            for (int i = 0; i < numbers; i++) {
                for (int j = i + 1; j < numbers; j++) {
                    if (numbersArray[i] > numbersArray[j]) {
                        int temp = numbersArray[i];
                        numbersArray[i] = numbersArray[j];
                        numbersArray[j] = temp;
                    }
                }
            }

            cout << numbersArray[numbers / 2 - 1] << " " << numbersArray[numbers / 2] << endl;
        }
    } else if (testCase == 5) {
        // Print out the sorted array of values that are between a range of 100 to 999

        for (int i = 0; i < numbers; i++) {
            for (int j = i + 1; j < numbers; j++) {
                if (numbersArray[i] > numbersArray[j]) {
                    int temp = numbersArray[i];
                    numbersArray[i] = numbersArray[j];
                    numbersArray[j] = temp;
                }
            }
        }

        for (int i = 0; i < numbers; i++) {
            if (numbersArray[i] >= 100 && numbersArray[i] <= 999) {
                cout << numbersArray[i] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}