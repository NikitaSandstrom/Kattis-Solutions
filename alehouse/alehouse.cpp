/*  Author:             Nikita Sandstrom
*   Last Updated:       11/11/2021
*   File Name:          alehouse.cpp
*   Kattis Attempted:   Alehouse
*/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    // Starting Variables
    int numOfGuests, lengthOfStay;
    vector<pair<int,char>> timings;
    cin >> numOfGuests >> lengthOfStay;
    int result = 0;
    int friends = 0;

    // Gather input and push i (in) if it is the in time, and o (out) if it
    // is the out time
    for (int i = 0; i < numOfGuests; i++) {
        int in, out;
        cin >> in >> out;
        /* subtract in with the lengthOfStay to normalize
        *  the arrays to find as many people you can meet
        *  in the period of time
        */
        timings.push_back(make_pair(in - lengthOfStay, 'i'));
        timings.push_back(make_pair(out, 'o'));
    }

    // Sort the list out (first value major order)
    sort(timings.begin(), timings.end());

    // Iterates through the itinerary of people who enter and leave at times
    for (int i = 0; i < numOfGuests * 2; i++) {
        //If a person enters the bar
        if (timings[i].second == 'i') {
            friends++;
        } else { // if they leave the bar
            friends--;
        }
        //finding the maximizer of the result
        result = max(result, friends);
    }

    cout << result;
}