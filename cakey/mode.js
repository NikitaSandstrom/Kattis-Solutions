const mode = a => {
    const count = {};
    
    a.forEach(e => { //for each element in array
      if (!(e in count)) { //if e is in the count, then skip as key already held
        count[e] = 0;
      }
  
      count[e]++; //Count up key of value by 1
    });
  
    let bestElement;
    let bestCount = 0;
  
    Object.entries(count).forEach(([k, v]) => { //take the hashmap and for each key & value
      if (v > bestCount) { //if the value is > the best count
        bestElement = k;
        bestCount = v;
      }
    });
    
    return bestElement;
  };

console.log(mode([1,2,3,4,5,6,7,7]));
console.log(mode([1,1,3,4,5,6,7,7]));
console.log(mode([1,1,1,4,5,6,7,7]));
console.log(mode([1,2,3,3,3,6,3,7]));
console.log(mode([1,3,3,4,5,2,2,1]));
console.log(mode([1,3,3,4,5,2,2,1]));
console.log(mode([]));