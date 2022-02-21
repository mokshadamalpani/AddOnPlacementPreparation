const stringContainNumber=(arr) => {
  let newarr=[];
  for(let i=0;i<arr.length;i++)
  {
      if(/\d/.test(arr[i]))
        newarr.push(arr[i]);
  }
  return newarr;
}
                                                            arr=["abc","abc1"];
 console.log(stringContainNumber(arr));                                                        

                                                          