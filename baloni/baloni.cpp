#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (v[t] == 0) {
            v[t-1]++;
        } else {
            v[t-1]++;
            v[t]--;
        }
    }

    int arrows = 0;
    for (int i = 0; i < n; i++) {
        arrows += v[i];
    }
    cout << arrows << endl;
}