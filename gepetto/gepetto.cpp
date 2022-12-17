#include <iostream>
#include <set>

using namespace std;

bool valid(set<pair<int,int>>& s, int n) {
    set<int> in;
    int i = 1;
    while (n > 0) {
        if(n % 2) {
            in.insert(i);
        }
        i++;
        n = n / 2;
    }

    for(auto i : s) {
        if(in.count(i.first) && in.count(i.second)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int,int>> v;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) {
            swap(a,b);
        }
        v.insert({a,b});
    }

    int ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        if(valid(v, i)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}