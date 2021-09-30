//Requirements//
//var counter = 0;
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

//Main Program Code//
//Gathering User Input
readline.question('', value => {
    readline.question('', value1 => {
        //Splits up the value1 result and converts to Number
        var argArray = value1.split(" ").map(Number).sort();
        //Creates the inclusion-exclusion array and sets all values to false
        var arrInclusion = Array(Number(value));
        for (var i = 0; i < arrInclusion.length; i++) {
            arrInclusion[i] = false;
        }

        //Checking if 1st & 2nd values satisfies conditions
        if (Number(value) >= 1 && Number(value) <= 40) {
            if (checkFruitWeight(argArray)) {
                var totalWeight = subsetSum(argArray, 0, Number(value), arrInclusion); //in NodeJS, all user inputs are Strings, mapping and converting to Int required
                console.log(totalWeight);
                //console.log(counter);
            }
        }
        readline.close(); //closes both readline prompts and stops the program in essence
    });
});

//HELPER FUNCTIONS

//Helper Function to check if every integer inputted
//the user is less than 1000. Can already assume each
//value is greater than 50
function checkFruitWeight(ValueArray) {
    for (var i = 0; i < ValueArray.length; i++) {
        if (ValueArray[i] > 1000 || ValueArray[i] < 50)
            return false;
    }
    return true;
}

//Helper Function that adds up all the true values
//And returns the total sum of the array. 
function addValues(arrValues, arrTrueFalse, level) {
    var totalSum = 0;
    for (var i = 0; i < level+1; i++) {
        if (arrTrueFalse[i]) {
            totalSum += arrValues[i];
        }
    }
    return totalSum;
}

/**
* A subset sum formula that checks through the entire binary tree
* and accumalates all possible combinations of nodes whose sum
* is greater than or equal to 200. Returns a Number with the total 
* sum of all the baskets.
* @param {Array[Number]} arrVal an array of values (sorted or unsorted)
* @param {Number} currentLevel current level inside of the tree
* @param {Number} height total height of the tree
* @param {Array[Boolean]} arrInc an array of Booleans that keep track of whether a value at position arrInc[currentLevel] is to be counted
* @returns {Number} The total sum of valid subsets in the tree.
*/
function subsetSum(arrVal, currentLevel, height, arrInc) {
    //counter++;
    var leftChild = 0, rightChild = 0, tempCounter = 0, remainingSum = 0, sub4Sum = 0;

    if (currentLevel == height-1) { //This case will only run in a height < 5 case since anything > 5 is guaranteed to be greater than 200
        arrInc[currentLevel] = true; //The subset with the leaf
        sub4Sum = addValues(arrVal, arrInc, currentLevel);
        if (sub4Sum < 200)
            return 0; //If at the leaf the total is less than 200, then return 0. It's not needed to check the case where you don't include the leaf as that is guaranteed to be < 200.
        return sub4Sum;

    } else {
        arrInc[currentLevel] = true; //Checking node (left child) where you include the value
        tempCounter = addValues(arrVal, arrInc, currentLevel);
        if (tempCounter >= 200) { //If the left child counter is greater than 200, then all subsets below that node are valid answers as well
            for (var i = currentLevel+1; i < height; i++)
                remainingSum += arrVal[i]; //Adding up all remaining values from index of current value to the leaves of the tree (height)
            leftChild = Math.pow(2, height-currentLevel-2) * (2 * tempCounter + remainingSum);
            /* Since worst case of a subset formula is O(2^n), we multiply through 2^n minus from the current level we are at as well minus 2 in case a solution
            |* is found at i = 0 where the rest of the subtree of the left child of the root is valid, which counteracts with the 2 in the right side with tempcounter
            |* and remaining sum.
            */ 
        } else {
            leftChild = subsetSum(arrVal, currentLevel+1, height, arrInc);
            //if less than 200, traverse further down the tree for the left child.
        }

        //Checking the Right Child
        tempCounter = 0;
        arrInc[currentLevel] = false; //The case where the argument value at this level is not counted
        tempCounter = addValues(arrVal, arrInc, currentLevel);
        if (tempCounter >= 200) {
            for (var i = currentLevel+1; i < height; i++)
                remainingSum += arrVal[i];
            rightChild = Math.pow(2, height-currentLevel-2) * (2 * tempCounter + remainingSum);
            //See above with the left child
        } else {
            rightChild = subsetSum(arrVal, currentLevel+1, height, arrInc);
            //Traverse along the right child of the subtree.
        }
        return leftChild + rightChild;
    }
}