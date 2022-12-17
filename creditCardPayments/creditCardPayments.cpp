#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double r,b,m;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> r >> b >> m;
        r = r / 100;
        bool success = false;

        for(int j = 1; j <= 1200; j++) {
            double interest = b * r;
            interest = round(interest * 100) / 100;
            b += interest;
            b = round(b * 100) / 100;
            b -= m;
            if(b < 1e-3) {
                cout << j << endl;
                success = true;
                break;
            }
        }
        if(!success) {
            cout << "impossible" << endl;
        }
    }
}