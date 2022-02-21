
const convert=(str) =>
{
    let arr=str.split(" ")
    if(arr[2]=="function()")
        arr.splice(2,1,"()","=>")
    else
        arr.splice(2,2,"function()")
    return arr;
}

console.log(convert("hello = function() { return 'hello'}").toString())
console.log(convert("hello = () => { return 'hello'}").toString())