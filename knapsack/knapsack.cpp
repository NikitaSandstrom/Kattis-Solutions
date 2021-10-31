/*  Author:             Nikita Sandstrom
*   Last Updated:       --/--/2021
*   File Name:          knapsack.cpp
*   Kattis Attempted:   Knapsack
*/ 

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> totalList;

int knapSack(int maxWeight, int knapsackListValue[], int knapsackListWeight[], int size) {
    int table[size + 1][maxWeight + 1];

    for (int i = 0; i <= size; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0) {
                table[i][w] = 0;
            } else if (knapsackListWeight[i - 1] > w) {
                table[i][w] = table[i - 1][w];
            } else {
                table[i][w] = max(knapsackListValue[i] + table[i - 1][w - knapsackListWeight[i]], table[i - 1][w]);
            }
        }
    }

    return table[size][maxWeight];
}

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
        int testCaseMaxWeight = totalList[0][0];
        int testCaseSize = totalList[0][1];
        totalList.erase(totalList.begin());

        int testCaseValue[testCaseSize];
        int testCaseWeight[testCaseSize];

        for (int i = 0; i < testCaseSize; i++) {
            testCaseValue[i] = totalList[0][0];
            testCaseWeight[i] = totalList[0][1];

            totalList.erase(totalList.begin());
        }

        cout << knapSack(testCaseMaxWeight, testCaseValue, testCaseWeight, testCaseSize);
    }
}



