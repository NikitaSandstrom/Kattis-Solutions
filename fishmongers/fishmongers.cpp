#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    long n, m;
    long result = 0;
    cin >> n >> m;

    vector<long> weights(n);
    vector<pair<long, long>> salespeople(m);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.rbegin(), weights.rend());
    
    for(int i = 0; i < m; i++) {
        cin >> salespeople[i].second >> salespeople[i].first;
    }

    sort(salespeople.rbegin(), salespeople.rend());
    
    int a = 0;
    int b = 0;
    while(a < n) {
        result += weights[a] * salespeople[b].first;
        salespeople[b].second--;
        if(salespeople[b].second == 0) {
            b++;
        }
        a++;
    }
    cout << result << endl;
}