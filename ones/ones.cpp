#include <iostream>
using namespace std;

main() {
    long long n;
    while (cin >> n) {
        int digs = 1;
        long long rem = 1;
        while (rem%n != 0) {
            rem = (rem * 10 + 1) % n;
            digs++;
        }     
        cout << digs << endl;
    }
}