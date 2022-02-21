function depth(arr) {
  let count=1
  let temp = arr;
  
 while (Array.isArray(temp)) {
    for (let item of temp) {
      if (Array.isArray(item)) {
        temp = item;
        count++;
        break;
      } else {
        temp = item;
      }
    }
  }
  return count;
}
  
console.log(depth([1, [2, [3,[ 4]]]]));