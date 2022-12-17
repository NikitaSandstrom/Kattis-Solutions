#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double arr[1000001];
    arr[0] = 0;
    for (int x = 1; x <= 1000000; x++)
        arr[x] = arr[x - 1] + log10(x);
    int num;
    while (cin >> num)
        cout << (int)arr[num] + 1 << endl;
}