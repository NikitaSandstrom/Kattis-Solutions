#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> ans(1000001, 0);
    long fac = 1;
    for(int i = 1; i <= 1000000; i++) {
        fac *= i;
        while(fac % 10 == 0) {
            fac /= 10;
        }
        ans[i] = fac % 10;
        fac %= 1000000;
    }

    long n;
    while(cin >> n && n != 0) {
        cout << ans[n] << endl;
    }

    return 0;
}