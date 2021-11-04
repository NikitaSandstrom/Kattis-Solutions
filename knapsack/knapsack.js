const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

var indexResults = new Array();

async function main () {
    for(var a = 0; a < 30; a++) {
        var inputInVal = await input();
        inputInVal = inputInVal.split(" ").map(Number);

        var totalList = new Array();
        totalList.push([0,0]);

        var table = new Array(inputInVal[1] + 1);

        for (var i = 0; i < inputInVal[1]; i++) {
            var objItem = await input();
            objItem = objItem.split(" ").map(Number);
            totalList.push(objItem);
        }

        for (var i = 0; i <= inputInVal[1]; i++) {
            table[i] = new Array(inputInVal[0] + 1);
            for (var w = 0; w <= inputInVal[0]; w++) {
                if (i == 0 || w == 0) {
                    table[i][w] = 0;
                } else if (totalList[i][1] > w) {
                    table[i][w] = table[i - 1][w];
                } else {
                    table[i][w] = Math.max(totalList[i][0] + table[i-1][w - totalList[i][1]], table[i - 1][w]);
                }
            }
        }
        
        knapSackIndices(table, inputInVal[1], inputInVal[0], totalList);

        console.log(indexResults.length);
        var stringBuilder = "";
        for (var i = 0; i < indexResults.length; i++) {
            stringBuilder += indexResults[i];
            if (i != indexResults.length - 1) {
                stringBuilder += " ";
            }
        }
        console.log(stringBuilder);
        indexResults = [];
    }
    
}

function knapSackIndices(knapsackTable, n, W, objPairs) {
    if (knapsackTable[n][W] == 0) {
        return;
    } else if (knapsackTable[n-1][W] == knapsackTable[n][W]) {
        knapSackIndices(knapsackTable, n-1, W, objPairs);
    } else {
        knapSackIndices(knapsackTable, n-1, W - objPairs[n][1], objPairs);
        indexResults.push(n-1);
    }
}


async function input() {    //Function to get input, bypassing NodeJS's synchronous input
    return (await readline[Symbol.asyncIterator]().next()).value;
}

main();
