/*  Author:             Nikita Sandstrom
*   Last Updated:       03/10/2022
*   File Name:          uniqueSnowflakes.cpp
*   Kattis Attempted:   Unique Snowflakes
*/ 

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++) {
        int numSnowflakes;
        cin >> numSnowflakes;

        map<long, long> snowflakeMap;
        long snowflake;
        long currentUniqueSnowflakes = 0;

        for (int j = 0; j < numSnowflakes; j++) {
            cin >> snowflake;

            if (snowflakeMap.find(snowflake) == snowflakeMap.end()) {
                snowflakeMap[snowflake] = j;
                currentUniqueSnowflakes++;
            }
        }

        cout << currentUniqueSnowflakes << endl;
    }
}