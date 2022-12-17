/*  Author:             Nikita Sandstrom
*   Last Updated:       03/10/2022
*   File Name:          uniqueSnowflakes.cpp
*   Kattis Attempted:   Unique Snowflakes
*/ 

#include <bits/stdc++.h>

using namespace std;

unordered_set<int> s;

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++) {
        int numSnowflakes;
        cin >> numSnowflakes;
        s.clear();

        deque<int> snowflakeDeque;
        int snowflake;
        int currentUniqueSnowflakes = 0;

        for (int j = 0; j < numSnowflakes; j++) {
            cin >> snowflake;

            if(s.count(snowflake)<=0) {
                s.insert(snowflake);
                snowflakeDeque.push_back(snowflake);
            } else {
                while(snowflakeDeque.front() != snowflake) {
                    s.erase(snowflakeDeque.front());
                    snowflakeDeque.pop_front();
                }
                snowflakeDeque.pop_front();
                snowflakeDeque.push_back(snowflake);
            }

            currentUniqueSnowflakes = max(currentUniqueSnowflakes, (int)snowflakeDeque.size());
        }

        cout << currentUniqueSnowflakes << endl;
    }
}