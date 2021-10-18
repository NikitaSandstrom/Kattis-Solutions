require('events').EventEmitter.defaultMaxListeners = 1000000;

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

var patientsArr = new Array();
//var highestPriorityCat = new Array(["", 0]);


async function main() {
    const num = await input();
    //Iterates through as many commands needed, splits the entries, and puts them against the if statement.
    for (var i = 0; i < Number(num); i++) {
        var commandArr = await input();
        commandArr = commandArr.split(" ");

        if(commandArr[0] == "0") {
            arriveAtClinic(commandArr[1], commandArr[2]);
        } else if (commandArr[0] == "1") {
            updateInfectionLevel(commandArr[1], commandArr[2]);
        } else if (commandArr[0] == "2") {
            treated(commandArr[1]);
        } else {
            query();
        }
    }

    readline.close();
}

async function input() {
    return (await readline[Symbol.asyncIterator]().next()).value;
}

function arriveAtClinic(catName, infectionLevel) {
    //Enters the Cat into the array
    var tempArray = [catName, Number(infectionLevel)]; //New entry: Cat's name, the infectionlevel of the cat
    patientsArr.push(tempArray);
    /*
    if (infectionLevel > highestPriorityCat[1]) {
        highestPriorityCat[0] = catName;
        highestPriorityCat[1] = infectionLevel;
    }*/

    //BST.insert(infectionLevel);
}

function updateInfectionLevel(catName, increaseInfection) {
    //STEP 1: update priority of cats in the infection level past index of current cat
    //STEP 2: update infection level of the current cat
    //STEP 3: update priority of the cats after the current index of current cat
    var getIndexVar = 0;

    //STEP 1
    for (var i = 0; i < patientsArr.length; i++) {
        if (patientsArr[i][0] == catName) {
            getIndexVar = i;
        }
    }

    //STEP 2
    patientsArr[getIndexVar][1] = patientsArr[getIndexVar][1] + Number(increaseInfection);
    /*
    if (patientsArr[getIndexVar][1] > highestPriorityCat[1]) {
        highestPriorityCat[0] = catName;
        highestPriorityCat[1] = infectionLevel;
    }*/
}

function treated(catName) {
    //search array for catname and make values null
    //check cats after index and reduce num priority as needed.
    for (var i = 0; i < patientsArr.length; i++) {
        if (patientsArr[i][0] == catName) {
            patientsArr[i][0] = null;
            patientsArr[i][1] = null;
            patientsArr[i][2] = null;
        }
    }
}

function query() {
    //Go through list, check if infection is > previous highest value
    //if value still equals 0, return "The clinic is empty"
    var catIndex = -1;
    var currentHighest = 29;

    for (var i = 0; i < patientsArr.length; i++) {
        if (patientsArr[i][1] > currentHighest) {
            catIndex = i;
            currentHighest = patientsArr[i][1];
        }
    }

    if (currentHighest == 29) { 
        console.log("The clinic is empty");
    } else {
        console.log(patientsArr[catIndex][0]);
    }
}

main();