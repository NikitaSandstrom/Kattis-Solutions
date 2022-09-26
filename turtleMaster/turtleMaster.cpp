/*  Author:             Nikita Sandstrom
*   Last Updated:       13/09/2022
*   File Name:          turtleMaster.cpp
*   Kattis Attempted:   Turtle Master
*/ 

#include <iostream>

using namespace std;

int main() {
    int x;
    int y;
    int direction;
    int commandCount;
    char command;
    int diamondX, diamondY;

    //initialize an 8x8 grid
    char grid[8][8];

    // input the grid
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'D') {
                diamondX = i;
                diamondY = j;
            }
        }
    }

    string commands;
    cin >> commands;

    //convert string into char array
    char commandArray[commands.length()];
    for (int i = 0; i < commands.length(); i++) {
        commandArray[i] = commands[i];
    }

    cout << endl;

    //Turtle's initial position is at the bottom left corner of the grid facing right
    x = 7;
    y = 0;
    direction = 1;

    //loop through the commands
    for (int i = 0; i < commands.length(); i++) {
        command = commandArray[i];
        if (command == 'L') {
            if (direction == 0) {
                direction = 3;
            } else {
                direction--;
            }
        } else if (command == 'R') {
            if (direction == 3) {
                direction = 0;
            } else {
                direction++;
            }
        } else if (command == 'F') {
            if (direction == 0) {
                if (grid[x-1][y] == 'C' || grid[x-1][y] == 'I') {
                    cout << "Bug!" << endl;
                    exit(0);
                } else {
                    grid[x][y] = '.';
                    x--;
                    grid[x][y] = 'T';
                }
            } else if (direction == 1) {
                if (grid[x][y+1] == 'C' || grid[x][y+1] == 'I') {
                    cout << "Bug!" << endl;
                    exit(0);
                } else {
                    grid[x][y] = '.';
                    y++;
                    grid[x][y] = 'T';
                }
            } else if (direction == 2) {
                if (grid[x+1][y] == 'C' || grid[x+1][y] == 'I') {
                    cout << "Bug!" << endl;
                    exit(0);
                } else {
                    grid[x][y] = '.';
                    x++;
                    grid[x][y] = 'T';
                }
            } else if (direction == 3) {
                if (grid[x][y-1] == 'C' || grid[x][y-1] == 'I') {
                    cout << "Bug!" << endl;
                    exit(0);
                } else {
                    grid[x][y] = '.';
                    y--;
                    grid[x][y] = 'T';
                }
            }
        } else if (command == 'X') {
            if (direction == 0) {
                if (grid[x-1][y] == 'I') {
                    grid[x-1][y] = '.';
                } else {
                    cout << "Bug!" << endl;
                    exit(0);
                }
            } else if (direction == 1) {
                if (grid[x][y+1] == 'I') {
                    grid[x][y+1] = '.';
                } else {
                    cout << "Bug!" << endl;
                    exit(0);
                }
            } else if (direction == 2) {
                if (grid[x+1][y] == 'I') {
                    grid[x+1][y] = '.';
                } else {
                    cout << "Bug!" << endl;
                    exit(0);
                }
            } else if (direction == 3) {
                if (grid[x][y-1] == 'I') {
                    grid[x][y-1] = '.';
                } else {
                    cout << "Bug!" << endl;
                    exit(0);
                }
            }
        }
        
    }

    if (x == diamondX && y == diamondY) {
        cout << "Diamond!" << endl;
    } else {
        cout << "Bug!" << endl;
    }

    return 0;
}