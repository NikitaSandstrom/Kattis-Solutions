/*  Author:             Nikita Sandstrom
*   Last Updated:       --/--/2021
*   File Name:          knapsack.cpp
*   Kattis Attempted:   Knapsack
*/ 

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> totalList;

int main() {
    int valueL, valueR;
    while(cin >> valueL >> valueR) {
        cin >> valueL >> valueR;
        vector<int> nextRow;
        nextRow.push_back(valueL);
        nextRow.push_back(valueR);

        totalList.push_back(nextRow);
    }

    while(!totalList.empty()) {
        //Change the Vector into a list, should reduce some *memory* or timing issues if they arise
        vector<vector<int>> testCaseList;
        int testCaseWeight = totalList[0][0];
        int testCaseSize = totalList[0][1];
        testCaseList.erase(testCaseList.begin());


        for (int i = 0; i < testCaseSize; i++) {
            vector<int> testCaseRow;
            testCaseRow.push_back(totalList[0][0]);
            testCaseRow.push_back(totalList[0][1]);

            testCaseList.push_back(testCaseRow);
            testCaseList.erase(testCaseList.begin());
        }

        knapsack(testCaseWeight, testCaseList);
    }
}



int knapsack(int maxWeight, vector<vector<int>> knapsackList) {
    if (knapsackList.size() == 0 || maxWeight == 0) {
        return 0;
    }
}