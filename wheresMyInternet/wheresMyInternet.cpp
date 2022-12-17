#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    deque<int> myDeque = {0};
    int size, edges, src, dest;
    bool allVisited = false;

    cin >> size >> edges;
    vector<bool> visited(size, false);
    visited[0] = true;
    vector<vector<int>> adjList(size);

    for (int i = 0; i < edges; i++) {
		cin >> src >> dest;
		adjList[src-1].push_back(dest-1);
		adjList[dest-1].push_back(src-1);
	}

    while(myDeque.size()) {
        int top = myDeque.front();
        myDeque.pop_front();
        
        for (auto i : adjList[top]) {
            if (!visited[i]) {
                visited[i] = true;
                myDeque.push_back(i);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            allVisited = true;
            cout << i + 1 << endl;
        }
    }

    if (!allVisited) {
        cout << "Connected" << endl;
    }
}