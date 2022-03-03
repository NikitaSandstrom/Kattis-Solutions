/*  Author:             Nikita Sandstrom
*   Last Updated:       13/12/2021
*   File Name:          crosscountry.cpp
*   Kattis Attempted:   Cross Country
*/ 

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <list>

int maximumInt = 2147483647;

using namespace std;

int main() {
    //starting variables
    int n, s, t;
    int val;
    
    cin >> n >> s >> t;

    vector<pair<int,int>> adjList[n];

    //adds values into adj List
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            //remove unimportant data (aka unvisitable nodes)
            if (val != 0) {
                adjList[i].push_back(make_pair(j, val));
            }
        }
    }

    //Creates Priority Queue for vertices
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> priQueue;
    vector<int> dist(n, maximumInt); //all distances from source infinite
                
    priQueue.push(make_pair(0, s)); //push source node
    dist[s] = 0; //distance to source always 0
    
    //While running through Priority Queue
    while (!priQueue.empty()) {
        int u = priQueue.top().second; //allocate memory for closest minimum distance
        priQueue.pop();

        //Use iterator to go through all (valid) end-nodes for vertex u
        vector<pair<int,int>>::iterator j;
        for (j = adjList[u].begin(); j != adjList[u].end(); ++j) {
            //end node and its weight
            int v = (*j).first;
            int w = (*j).second;

            //if dist from u + w is less than current distance to v
            if (dist[u] + w < dist[v]) {
                //update distance to v, and add to queue
                dist[v] = dist[u] + w;
                priQueue.push(make_pair(dist[v],v));
            }
        }
    }

    //print distance to sink
    cout << dist[t];
    
}