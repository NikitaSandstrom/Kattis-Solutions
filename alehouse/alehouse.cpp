/*  Author:             Nikita Sandstrom
*   Last Updated:       10/11/2021
*   File Name:          alehouse.cpp
*   Kattis Attempted:   Alehouse
*/ 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int numOfGuests, lengthOfStay;
    cin >> numOfGuests >> lengthOfStay;
    int startTimes [numOfGuests], endTimes [numOfGuests];
    vector<int> overlaps;
    int maxOverlaps = 0;

    for (int i = 0; i < numOfGuests; i++) {
        cin >> startTimes[i] >> endTimes[i];
    }

    sort(startTimes, startTimes + numOfGuests);
    sort(endTimes, endTimes + numOfGuests);

    for (int i = 0; i < numOfGuests; i++) {
        int overlaps = 0;
        for (int j = i; j < numOfGuests; j++) {
            if (startTimes[j] - endTimes[i] <= lengthOfStay) {
                overlaps++;
            }
        }
        maxOverlaps = max(maxOverlaps, overlaps);
    }

    cout << maxOverlaps;
}