#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int main(){
    int N, L, P, maxDistance = 0;
    
    cin >> N >> L >> P;

    vector<int> cars(N, 0);

    for (int i=0; i<P; i++) {
        int x;
        cin >> x;

        if (x > N * L) {
            maxDistance = max(maxDistance, x - N*L + L/2);
            cars[N-1] ++;
        } else if (x % L == 0) {
            maxDistance = max(maxDistance, L/2);
            if (x == N * L) {
                cars[N - 1]++;
            } else {
                cars[x/L]++;
            }
        } else if (x % L < L/2) {
            int distance = L/2 - (x % L);
            maxDistance = max(maxDistance, distance);
            cars[x/L] ++;
        } else {                  
            int distance = (x % L) - L/2;
            maxDistance = max(maxDistance, distance);
            cars[x/L] ++;
        }
    }

    cout << maxDistance << endl;
    cout << *max_element(cars.begin(), cars.end()) << endl;
}