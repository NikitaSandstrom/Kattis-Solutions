/*  Author:             Nikita Sandstrom
*   Last Updated:       16/10/2021
*   File Name:          cakey.js
*   Kattis Attempted:   Cakey McCakeFace
*/ 

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

var inputInNum, inputOutNum, inputInVal, inputOutVal; //Variable Declarations
const count = {};
let bestElement = 0;
let bestCount = 0;

async function main() {
    //Taking Inputs and converting to Numbers
    inputInNum = await input();
    inputOutNum = await input();
    inputInVal = await input();
    inputOutVal = await input();

    inputInNum = Number(inputInNum);
    inputOutNum = Number(inputOutNum);
    inputInVal = inputInVal.split(" ").map(Number);
    inputOutVal = inputOutVal.split(" ").map(Number);

    //double for loop to input all positive differences into the object count
    //while loop referenced from Paul Kelley to implement a faster algorithm
    for (var i = 0, iterator = 0; i < inputInNum; i++) {
        while (iterator < inputOutNum && inputOutVal[iterator] <= inputInVal[i]) { //Code sectioned assisted by Paul Kelley
            iterator++;
        }
        for (var j = iterator; j < inputOutNum; j++) {
            var diff = inputOutVal[j] - inputInVal[i];
            if (diff > -1) {
                if (!(diff in count)) {
                    count[diff] = 0; //creates new key with value 0
                }
                count[diff]++; //increases value inside the key
            }
        }
    }
    
    Object.entries(count).forEach(([k, v]) => { //Takes the key and value from each reference in the Object count
        if (v > bestCount) {                    //If value of current Key is greater than the current largest count
            bestElement = k;
            bestCount = v;
        } else if (v == bestCount) {            //If the count is equal to the best count, check to see which key is smaller
            bestCount = Math.min(bestElement, k);
        }
    });

    console.log(bestElement);
    
    readline.close();
}

async function input() {    //Function to get input, bypassing NodeJS's synchronous input
    return (await readline[Symbol.asyncIterator]().next()).value;
}

main();