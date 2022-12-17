#include <iostream>
#include <vector>

using namespace std;

int main() {
    int iterations;
    cin >> iterations;

    for (int i = 0; i < iterations; i++) {
        int count = 0;
        int n, m;
        vector<int> v;
        vector<vector<int>> adjList;
        cin >> n >> m;

        bool visited[n];

        for (int j = 0; j < n; j++) {
            adjList.push_back(vector<int>());
        }

        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adjList[a].push_back(b);
        }

        // Start at the first node and determine if it not has been visted yet. If not, mark as visited and increment count. Then, mark its neighbor as visited and go to that node's neightbor. Repeat until all nodes have been visited.
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                count++;
                visited[j] = true;
                for (int k = 0; k < adjList[j].size(); k++) {
                    visited[adjList[j][k]] = true;
                }
            } if (!visited[adjList[j][0]]) {
                visited[adjList[j][0]] = true;
            }
        }

        cout << count << endl;
    }
}