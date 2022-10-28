/*  Author:             Nikita Sandstrom
*   Last Updated:       30/09/2022
*   File Name:          anEyeForAnI.cpp
*   Kattis Attempted:   An Eye for an I
*/ 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int numRuns;
    cin >> numRuns;

    for (int i = 0; i < numRuns; i++) {
        //gather line of input into a variable
        string input;
        cin >> input;

        //split the input by the space character and put into a string vector
        vector<string> splitInput;
        vector<string> edittedInput;
        string temp = "";
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ' ') {
                splitInput.push_back(temp);
                temp = "";
            } else {
                temp += input[i];
            }
        }

        string originalWord;
        string lettersToCondense;
        string edittedWord;

        //go through the vector and for each word, check the characters if they can be condensed
        for (int i = 0; i < splitInput.size(); i++) {
            originalWord = splitInput[i];
            lettersToCondense = "";
            edittedWord = "";

            //check if the word can be condensed
            for (int j = 0; j < originalWord.length(); j++) {
                if (originalWord[j] == 'i' || originalWord[j] == 'I') {
                    lettersToCondense += originalWord[j];
                } else {
                    edittedWord += originalWord[j];
                }
            }

            //if the word can be condensed, condense it
            if (lettersToCondense.length() > 0) {
                edittedWord += 'I';
            }

            //add the editted word to the editted input vector
            edittedInput.push_back(edittedWord);
        }

    }
}