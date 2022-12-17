#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int myMax = 2 << 28;

bool gridMovement(int m, int n, int x, int y) {
    if ( x < 0 || y < 0 || x >= m || y >= n ) {
        return false;
    }
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> grid;
    grid.resize(m, vector<int>(n));
    vector<vector<int>> dist;
    dist.resize(m, vector<int>(n, myMax));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char coord;
            cin >> coord;
            grid[i][j] = coord - '0';
        }
    }

    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0,0});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int range = grid[x][y];
        if(gridMovement(m, n, x-range, y)) {
            if(dist[x][y] + 1 < dist[x-range][y]) {
                dist[x-range][y] = dist[x][y] + 1;
                q.push({x-range,y});
            }
        }
        if(gridMovement(m, n, x+range, y)) {
            if(dist[x][y] + 1 < dist[x+range][y]) {
                dist[x+range][y] = dist[x][y] + 1;
                q.push({x+range,y});
            }
        }
        if(gridMovement(m, n, x, y-range)) {
            if(dist[x][y] + 1 < dist[x][y-range]) {
                dist[x][y-range] = dist[x][y] + 1;
                q.push({x,y-range});
            }
        }
        if(gridMovement(m, n, x, y+range)) {
            if(dist[x][y] + 1 < dist[x][y+range]) {
                dist[x][y+range] = dist[x][y] + 1;
                q.push({x,y+range});
            }
        }
    }

    int d = dist[m-1][n-1];
    if(d == myMax) {
        cout << "-1" << endl;
    }
    else {
        cout << d << endl;
    }


}