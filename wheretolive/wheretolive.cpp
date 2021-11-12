/*  Author:             Nikita Sandstrom
*   Last Updated:       10/11/2021
*   File Name:          alehouse.cpp
*   Kattis Attempted:   Alehouse
*/ 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int numOfLocations;
    while(cin >> numOfLocations) {
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