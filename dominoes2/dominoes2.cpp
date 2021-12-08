/*  Author:             Nikita Sandstrom
*   Last Updated:       07/12/2021
*   File Name:          dominoes2.cpp
*   Kattis Attempted:   Dominoes 2
*/ 

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int dfs(int z, vector<vector<int>>& adj, vector<int>& vertexSeen, int counter) {
    //mark vertex as seen
    vertexSeen[z] = 1;
    counter++;

    //create iterator type to go through each value in the adjaceny list
    vector<int>::iterator i;
    //traverse through each value of z in adjacency list
    for (i = adj[z].begin(); i != adj[z].end(); i++) {
        //if i pointing to vertexSeen not seen, do dfs
        if (vertexSeen[*i] != 1) {
            counter = dfs(*i, adj, vertexSeen, counter);
        }
    }
    return counter;
}

int main() {
    //Starting Variables
    int n, m, l, v, w;
    int vertex, numTestCases, finalAnswer;

    vector<vector<int>> adj;
    vector<int> vertexTable;

    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++) {
        cin >> n >> m >> l;

        //Vector Cleanup through each test case
        finalAnswer = 0;
        adj.clear();
        adj.resize(n + 1);
        vertexTable.clear();
        vertexTable.resize(n + 1, 0);

        //Gather vertex Pairs
        for (int j = 0; j < m; j++) {
            cin >> v >> w;
            adj[v].push_back(w);
        }

        //conduct dfs through each marked vertex
        for (int j = 0; j < l; j++) {
            cin >> vertex;
            if (vertexTable[vertex] != 1) {
                finalAnswer = dfs(vertex, adj, vertexTable, finalAnswer);
            }
        }

        //Output
        cout << finalAnswer;
        cout << endl;

    }
}