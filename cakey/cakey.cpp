/*  Author:             Nikita Sandstrom
*   Last Updated:       16/10/2021
*   File Name:          cakey.cpp
*   Kattis Attempted:   Cakey McCakeFace
*/ 

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    //Starting Variables
    unsigned long long inputInNum, inputOutNum;
    vector<int> inputInVal, inputOutVal;
    //Utilized for the Mode
    map<int,int> timings;
    int bestElement = 0;
    int bestCount = 0;

    //Pushing values into variables
    cin >> inputInNum >> inputOutNum;
    for(int i = 0; i < inputInNum; i++) {
        int val;
        cin >> val;
        inputInVal.push_back(val);
    }
    for(int i = 0; i < inputOutNum; i++) {
        int val;
        cin >> val;
        inputOutVal.push_back(val);
    }

    //simple double for loop to add values into the map for each key
    for(auto i: inputInVal) {
        for(auto j : inputOutVal) {
            timings[j-i]++;
        }
    }

    //For loop to find the mode of the smallest key in the map
    for(auto i: timings) {
        if(i.first > 0 && i.second > bestCount) { //if the key is positive and the value is larger than current bestCount
            bestElement = i.first;
            bestCount = i.second;
        } else if(i.first > 0 && i.second == bestCount) { //if value is equal to current bestCount, check the minimum between the two keys
            bestElement = min(bestElement, i.first);
        }
    }

    //printing out min mode time
    cout << bestElement << endl;

    return 0;
}