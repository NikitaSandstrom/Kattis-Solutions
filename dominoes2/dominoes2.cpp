/*  Author:             Nikita Sandstrom
*   Last Updated:       05/12/2021
*   File Name:          dominoes2.cpp
*   Kattis Attempted:   Dominoes 2
*/ 

#include <iostream>
#include <vector>

using namespace std;
int finalAnswer;

void dfs(int z, vector<pair<int,int>>& vertexPairs, vector<int>& verticesSeen) {
    //if vertex already seen, return
    //else, mark that vertex as seen and add 1
    
    //put in for loop (multiple branches off z)
    //if line exists from z to y, perform dfs
}


int main() {
    int n, m, l;
    int numTestCases;

    cin >> numTestCases;

    while (cin >> n >> m >> l) {
        //Starting Variables
        finalAnswer = 0;
        vector<pair<int, int>> totalList;
        vector<int> vertexTable(n, 0);
        vector<int> startingVertices;

        //Gather Domino Pairs
        for (int i = 0; i < m; i++) {
            pair<int, int> dominoHit;
            cin >> dominoHit.first >> dominoHit.second;
            totalList.push_back(dominoHit);
        }

        //Gathering Vertices to start knocking down        
        for (int i = 0; i < l; i++) { //Could be optimized further and combined with for loop below
            int vertex;
            cin >> vertex;
            startingVertices.push_back(vertex);
        }

        //Depth First Search
        //Takes starting vertex, totalList, and performs DFS along directed graph
        for (int i = 0; i < startingVertices.size; i++) {
            finalAnswer += dfs(startingVertices[i], totalList, vertexTable);
        }

        //Output
        cout << finalAnswer;
        cout << endl;
    }
}