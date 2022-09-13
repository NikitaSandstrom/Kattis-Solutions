/*  Author:             Nikita Sandstrom
*   Last Updated:       13/09/2022
*   File Name:          architecture.cpp
*   Kattis Attempted:   Architecture
*/ 

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int rows;
    int cols;
    
    cin >> rows >> cols;

    int rowArray[rows];
    int colArray[cols];

    for (int i = 0; i < rows; i++) {
        cin >> rowArray[i];
    }

    for (int i = 0; i < cols; i++) {
        cin >> colArray[i];
    }
    
    sort(rowArray, rowArray + rows);
    sort(colArray, colArray + cols);

    if(colArray[cols - 1] == rowArray[rows - 1]) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}