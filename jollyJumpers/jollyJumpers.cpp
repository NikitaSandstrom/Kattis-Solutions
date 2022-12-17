#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n;
    while (cin >> n) {
        vector<long> v(n);
        bool jolly = true;
        for (int i = 0; i < v.size(); i++) {
            cin >> v[i];
        }

        vector<bool> seen(n, false);

        for(int i = 1; i < n; i++) {
            long diff = abs(v[i] - v[i-1]);
            if(diff >= 0 && diff < n) {
                seen[diff] = true;
            }
        }

        for(int i = 1; i < n; i++) {
            jolly &= seen[i];
        }

        if (jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
}