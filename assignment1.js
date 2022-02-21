 const boomerangs=(arr) => {
   let subarr=[];
   let newarr=[];
   for(let i=0;i<arr.length;i++)
   {
       if(arr[i]===arr[i+2] && arr[i+1]!==arr[[i]])
       {
           subarr.push(arr[i]);
           subarr.push(arr[i+1]);
           subarr.push(arr[i+2]);
            newarr.push(subarr);
            subarr=[];
        }
   }
   return newarr;
};
let result=boomerangs([3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]);
console.log(result.length+' boomerangs in this sequence:')
console.log(result);
