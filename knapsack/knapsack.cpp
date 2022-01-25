/*  Author:             Nikita Sandstrom
*   Last Updated:       31/10/2021
*   File Name:          knapsack.cpp
*   Kattis Attempted:   Knapsack
*/ 

#include <iostream>
#include <vector>

using namespace std;

//Function that creates the table for the Knapsack Problem
void createTable(vector<pair<int, int>>& objPairs, vector<vector<int>>& knapsackTable, int W) {
    for (int i = 0; i < objPairs.size(); i++) {
        for (int w = 0; w <= W; w++) {
            //Recurrence utilized from slides.
            if (i == 0 || w == 0) {
                knapsackTable[i][w] = 0;
            } else if (objPairs[i].second > w) {
                knapsackTable[i][w] = knapsackTable[i - 1][w];
            } else {
                knapsackTable[i][w] = max(objPairs[i].first + knapsackTable[i - 1][w - objPairs[i].second], knapsackTable[i - 1][w]);
            }
        }
    }
}

//Function that searches the table and gathers the indices for the most optimal knapsack recurrence.
void knapSackIndices(vector<vector<int>>& knapsackTable, int n, int W, vector<int>& indexResults, vector<pair<int, int>>& objPairs) {
    //base case
    if(knapsackTable[n][W] == 0) {
        return;
    } else if(knapsackTable[n-1][W] == knapsackTable[n][W]) {
        //If the value previous is the same as the one being searched at this moment, then that means this indice did not fit the weight bounds
        //or was not optimal enough
        knapSackIndices(knapsackTable, n-1, W, indexResults, objPairs);
    } else {
        //Gather the index most optimal, check back one, as well as checking up.
        //Search method is in essence a diagonal search.
        knapSackIndices(knapsackTable, n-1, W-objPairs[n].second, indexResults, objPairs);
        //sends the index to vector 
        indexResults.push_back(n-1);
    }
}

int main() {
    int valueL, valueR;
    while(cin >> valueL >> valueR) {
        //Various starting lists
        vector<pair<int, int>> totalList;
        //sets index value for results, almost a dummy value
        totalList.push_back({0,0});
        vector<vector<int>> table;
        //sets table size immediately
        table.resize(valueR + 1, vector<int>(valueL + 1));
        vector<int> indexResults;

        //gathers input for that test case
        for(int i = 0; i < valueR; i++) {
            pair<int, int> objItem;
            cin >> objItem.first >> objItem.second;
            totalList.push_back(objItem);
        }

        //Helper Functions
        createTable(totalList, table, valueL);
        knapSackIndices(table, valueR, valueL, indexResults, totalList);

        //Output
        cout << indexResults.size() << endl;
        for(int i = 0; i < indexResults.size(); i++) {
            cout << indexResults[i] << " ";
        }
        cout << endl;
    }
}