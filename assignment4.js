function multiply(n)
{
    let product = 1;
    while (n != 0)
    {
        product = product * (n % 10);
        n = Math.floor(n / 10);
    }
    return product;
}

const singledigit =(num1,num2) => {
    let add=num1+num2;
    result=multiply(add);
    while(result.toString().length!=1)
    {
        result=multiply(result)
    }
    
    return result;
}

console.log(singledigit(125,234))