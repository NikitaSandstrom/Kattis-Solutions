/*  Author:             Nikita Sandstrom
*   Last Updated:       07/12/2021
*   File Name:          shortestpath1.cpp
*   Kattis Attempted:   Shortest Path 1
*/ 

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <list>

int maximumInt = 2147483647;

using namespace std;


void printSolution(vector<int> dist, int V)
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}

/*int dijkstraPath (vector<pair<int,int>> distList[], int source, int sink, int size) {
    

    /*
    int smallNode, minDist = maximumInt;
    int v, w;
    
    vector<bool> nodesVisted;
    nodesVisted.resize(size, false);


    dist.resize(size, maximumInt);
    dist[source] = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size; j++) {
            if (nodesVisted[j] == false && dist[j] <= minDist) {
                minDist = dist[j];
                smallNode = j;
            }
        }
        nodesVisted[smallNode] = true;
        for(auto it = distList[source].begin(); it != distList[source].end(); it++) {
            v = it -> first;
            w = it -> second;

            if (!nodesVisted[v] && w != 0 && dist[smallNode] != maximumInt && dist[smallNode] + w < dist[v]) {
                dist[v] = dist[smallNode] + w;
            }
            /*if(!nodesVisted[j] && distList[smallNode][j] && dist[smallNode] != maximumInt && dist[smallNode] + distList[smallNode][j] < dist[j]) {
                cout << "PING";
                dist[j] = dist[smallNode] + distList[smallNode][j];
            }
        }
    }
    printSolution(dist, size);
    return dist[sink];
}*/



//return distMatrix[source][i] + dijkstraPath(distMatrix, nodesVisted, i, sink);

int main() {
    int n, m, q, s, u, v, w;
    int vertex, finalAnswer;

    

    while (cin >> n >> m >> q >> s) {
        if (n + m + q + s != 0) {
            vector<pair<int,int>> adjList[n];

            for (int i = 0; i < m; i++) {
                cin >> u >> v >> w;

                adjList[u].push_back(make_pair(v, w));
            }

            for (int i = 0; i < q; i++) {
                cin >> vertex;
                //implement Dijkstra's





                priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> priQueue;
                vector<int> dist(n, maximumInt);
                
                priQueue.push(make_pair(0, s));

                dist[s] = 0;

                while (!priQueue.empty()) {
                    int u = priQueue.top().second;
                    priQueue.pop();

                    vector<pair<int,int>>::iterator j;
                    for (j = adjList[u].begin(); j != adjList[u].end(); ++j) {
                        int v = (*j).first;
                        int w = (*j).second;

                        if (dist[v] > dist[u] + w) {
                            dist[v] = dist[u] + w;
                            priQueue.push(make_pair(dist[v],v));
                        }
                    }
                }

                finalAnswer = dist[vertex];










                if (finalAnswer == maximumInt) {
                    cout << "Impossible";
                    cout << endl;
                } else {
                    cout << finalAnswer;
                    cout << endl;
                }
                
            }
        }
    } 
}