/*  Author:             Nikita Sandstrom
*   Last Updated:       06/12/2021
*   File Name:          dominoes2.cpp
*   Kattis Attempted:   Dominoes 2
*/ 

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int finalAnswer;
vector<vector<int>> adj;
vector<int> vertexTable;

void dfs(int z) {
    //Mark vertex as seen and add 1
    vertexTable[z-1] = 1;
    finalAnswer++;
    
    //put in for loop (multiple branches off z)
    //if line exists from z to y, perform dfs
    for(auto i : adj[z]) {
        cout << i;
        if (vertexTable[z - 1] == 0)
            dfs(i);
    }
}


int main() {
    int n, m, l, v, w, vertex;
    int numTestCases;

    cin >> numTestCases;

    while (cin >> n >> m >> l) {
        //Starting Variables & cleanup
        finalAnswer = 0;
        adj.resize(n);
        vertexTable.resize(n, 0);


        //Gather vertex Pairs
        for (int i = 0; i < m; i++) {
            cin >> v >> w;
            adj[v].push_back(w);
        }


        //Gathering Vertices to start marking down        
        for (int i = 0; i < l; i++) {
            cin >> vertex;
            if (!vertexTable[vertex-1])
                dfs(vertex);
        }

        //Output
        cout << finalAnswer;
        cout << endl;
    }
}