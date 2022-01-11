oneDigit=['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine']
twoDigit=['Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen']
tensDigit=['Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety']
suffix=['Thousand','Million','Billion','Trillion','Quadrillion','Quintillion','sextillion','']
def convert(str) :
    word=''
    if str[0]=='0' and str[1]=='0' and str[2]=='0':
      return word
    if len(str)==2 :
        if int(str)//10>=2 :
            word=tensDigit[(int(str)//10)-2]+oneDigit[int(str)%10]
        else :
            if str[0]=='0':
                word=oneDigit[int(str)]
            else :
                word=twoDigit[int(str)%10]
    elif len(str)==3 :
      if str[0]!='0':
        if int(str[1:])//10>=2 :
            word=oneDigit[int(str)//100]+' '+'Hundred'+' '+tensDigit[(int(str[1:])//10)-2]+' '+oneDigit[int(str[1:])%10]
        else :
            if str[1]=='0' :
                word=oneDigit[int(str)//100]+' '+'Hundred'+' '+oneDigit[int(str[1:])%10]
            else :
                word=oneDigit[int(str)//100]+' '+'Hundred'+' '+twoDigit[int(str[1:])%10]
      else :
        if int(str[1:])//10>=2 :
            word=oneDigit[int(str)//100]+' '+' '+tensDigit[(int(str[1:])//10)-2]+' '+oneDigit[int(str[1:])%10]
        else :
          if str[1]=='0':
              word=oneDigit[int(str[1:])%100]
          else :
              word=twoDigit[int(str[1:])%10]    
    return word            

wordf=''
wordfd=''
str=input("Enter Any Number :")
div=len(str)%3
pos=(len(str)//3)-1
if div==1 :
    wordfd=wordfd+''+oneDigit[int(str[0])]+' '+suffix[pos]+' '
    pos=pos-1
elif div==2 :
    wordfd=wordfd+' '+convert(str[0:2])+' '+suffix[pos]+' '
    pos=pos-1

j=(len(str)//3)-2
for i in range(div,len(str),3):
    wordf=convert(str[i:i+3])
    if wordf=='':
      j=j-1
    else:
      if i==len(str)-3 :
          wordfd=wordfd+wordf+' '
      else:
          wordfd=wordfd+wordf+' '+suffix[j]+' '
      j=j-1

print(wordfd)    
