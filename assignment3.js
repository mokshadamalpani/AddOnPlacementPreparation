const change=(number) => {
    var newarr=[];
    for(let i=0;i<number.length;i++)
    {
        newarr.push(Number(number[i]));
    }
    return newarr;
}
const countLoneones=(number) => {
    let arr=number.toString().split("")
    let newarr=change(arr);
    count=0;
    for(let i=0;i<newarr.length-1;i++)
        if(arr[i]==1 && (arr[i-1]!=arr[i] || arr[i+1]!=arr[i]))
            count+=1;
    return count;
}

console.log(countLoneones(1191));                       

                                                          