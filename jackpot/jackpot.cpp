#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int items;
        cin >> items;

        map<long, long> bestfactors;

        for (int j = 0; j < items; j++) {
            int item;
            cin >> item;

            map<long, long> factorshere;

            while(item > 1) {
                bool broken = false;
                for(long j = 2; j <= sqrt(item) + 1; j++) {
                    if(item % j == 0) {
                        item /= j;
                        factorshere[j]++;
                        broken = true;
                        break;
                    }
                }

                if(!broken) {
                    factorshere[item]++;
                    item = 1;
                }
            }

            for(auto i : factorshere) {
                long idx = i.first;
                if(factorshere[idx] > bestfactors[idx]) {
                    bestfactors[idx] = factorshere[idx];
                }
            }
        }

        long total = 1;
        bool toobig = false;
        for(auto i : bestfactors) {
            total *= pow(i.first, i.second);
            if(total > 1000000000) {
                toobig = true;
                break;
            }
        }

        if(toobig) {
            cout << "More than a billion." << endl;
        }
        else {
            cout << total << endl;
        }
    }
}