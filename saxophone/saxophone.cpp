/*  Author:             Nikita Sandstrom
*   Last Updated:       09/09/2022
*   File Name:          saxophone.cpp
*   Kattis Attempted:   Eb Alto Saxophone Player
*/ 

#include <iostream>

using namespace std;

class Fingers {
    public:
        bool finger1 = false;
        bool finger2 = false; 
        bool finger3 = false; 
        bool finger4 = false; 
        bool finger5 = false; 
        bool finger6 = false; 
        bool finger7 = false; 
        bool finger8 = false; 
        bool finger9 = false; 
        bool finger10 = false; 
};

int main() {
    int fingerNote1, fingerNote2, fingerNote3, fingerNote4, fingerNote5, fingerNote6, fingerNote7, fingerNote8, fingerNote9, fingerNote10;

    int chords;
    cin >> chords;

    for (int chordNum = 0; chordNum < chords; chordNum++) {
        fingerNote1 = 0;
        fingerNote2 = 0;
        fingerNote3 = 0;
        fingerNote4 = 0;
        fingerNote5 = 0;
        fingerNote6 = 0;
        fingerNote7 = 0;
        fingerNote8 = 0;
        fingerNote9 = 0;
        fingerNote10 = 0;
        Fingers fingers;
        string notes;
        cin >> notes;

        for (int i = 0; i < notes.size(); i++) {
            if (notes[i] == 'c') {
                if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                } if (fingers.finger7 == false) {
                    fingerNote7++;
                } if (fingers.finger8 == false) {
                    fingerNote8++;
                } if (fingers.finger9 == false) {
                    fingerNote9++;
                } if (fingers.finger10 == false) {
                    fingerNote10++;
                }

                fingers.finger1 = false;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = true;
                fingers.finger8 = true;
                fingers.finger9 = true;
                fingers.finger10 = true;
                
            } else if (notes[i] == 'd') {
                if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                } if (fingers.finger7 == false) {
                    fingerNote7++;
                } if (fingers.finger8 == false) {
                    fingerNote8++;
                } if (fingers.finger9 == false) {
                    fingerNote9++;
                }

                fingers.finger1 = false;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = true;
                fingers.finger8 = true;
                fingers.finger9 = true;
                fingers.finger10 = false;

            } else if (notes[i] == 'e') {
                if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                } if (fingers.finger7 == false) {
                    fingerNote7++;
                } if (fingers.finger8 == false) {
                    fingerNote8++;
                }

                fingers.finger1 = false;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = true;
                fingers.finger8 = true;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'f') {
                if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                } if (fingers.finger7 == false) {
                    fingerNote7++;
                }

                fingers.finger1 = false;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = true;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'g') {
                if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                }

                fingers.finger1 = false;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = false;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'a') {
                if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                }

                fingers.finger1 = false;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = false;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = false;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'b') {
                if (fingers.finger2 == false) {
                    fingerNote2++;
                }

                fingers.finger1 = false;
                fingers.finger2 = true;
                fingers.finger3 = false;
                fingers.finger4 = false;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = false;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'C') {
                if (fingers.finger3 == false) {
                    fingerNote3++;
                }

                fingers.finger1 = false;
                fingers.finger2 = false;
                fingers.finger3 = true;
                fingers.finger4 = false;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = false;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'D') {
                if (fingers.finger1 == false) {
                    fingerNote1++;
                } if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                } if (fingers.finger7 == false) {
                    fingerNote7++;
                } if (fingers.finger8 == false) {
                    fingerNote8++;
                } if (fingers.finger9 == false) {
                    fingerNote9++;
                }

                fingers.finger1 = true;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = true;
                fingers.finger8 = true;
                fingers.finger9 = true;
                fingers.finger10 = false;

            } else if (notes[i] == 'E') {
                if (fingers.finger1 == false) {
                    fingerNote1++;
                } if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                } if (fingers.finger7 == false) {
                    fingerNote7++;
                } if (fingers.finger8 == false) {
                    fingerNote8++;
                }

                fingers.finger1 = true;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = true;
                fingers.finger8 = true;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'F') {
                if (fingers.finger1 == false) {
                    fingerNote1++;
                } if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                } if (fingers.finger7 == false) {
                    fingerNote7++;
                }

                fingers.finger1 = true;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = true;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'G') {
                if (fingers.finger1 == false) {
                    fingerNote1++;
                } if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                } if (fingers.finger4 == false) {
                    fingerNote4++;
                }

                fingers.finger1 = true;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = true;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = false;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'A') {
                if (fingers.finger1 == false) {
                    fingerNote1++;
                } if (fingers.finger2 == false) {
                    fingerNote2++;
                } if (fingers.finger3 == false) {
                    fingerNote3++;
                }

                fingers.finger1 = true;
                fingers.finger2 = true;
                fingers.finger3 = true;
                fingers.finger4 = false;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = false;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            } else if (notes[i] == 'B') {
                if (fingers.finger1 == false) {
                    fingerNote1++;
                } if (fingers.finger2 == false) {
                    fingerNote2++;
                }

                fingers.finger1 = true;
                fingers.finger2 = true;
                fingers.finger3 = false;
                fingers.finger4 = false;
                fingers.finger5 = false;
                fingers.finger6 = false;
                fingers.finger7 = false;
                fingers.finger8 = false;
                fingers.finger9 = false;
                fingers.finger10 = false;

            }
        }

        cout << fingerNote1 << " " << fingerNote2 << " " << fingerNote3 << " " << fingerNote4 << " " << fingerNote5 << " " << fingerNote6 << " " << fingerNote7 << " " << fingerNote8 << " " << fingerNote9 << " " << fingerNote10 << endl;
    }

    return 0;
}