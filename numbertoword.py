oneDigit=['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine']
twoDigit=['Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen']
tensDigit=['Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety']
suffix=['Thousand','Million','Billion','Trillion','Quadrillion','Quintillion','sextillion']
def convert(str) :
    word=''
    if len(str)==1 :
        word=oneDigit[int(str)]
    elif len(str)==2 :
        if int(str)//10>=2 :
            word=tensDigit[(int(str)//10)-2]+oneDigit[int(str)%10]
        else :
            if str[0]=='0':
                word=oneDigit[int(str)]
            else :
                word=twoDigit[int(str)%10]
    elif len(str)==3 :
        if int(str[1:])//10>=2 :
            word=oneDigit[int(str)//100]+' '+'Hundred'+' '+tensDigit[(int(str[1:])//10)-2]+' '+oneDigit[int(str[1:])%10]
        else :
            if str[1]=='0':
                word=oneDigit[int(str)//100]+' '+'Hundred'+' '+oneDigit[int(str[1:])%10]
            else :
                word=oneDigit[int(str)//100]+' '+'Hundred'+' '+twoDigit[int(str[1:])%10]
    return word            

wordf=''
wordfd=''
str=input("Enter Any Number :")
e=len(str)%3
j=(len(str)//3)-1
if e==1 :
    wordfd=wordfd+''+oneDigit[int(str[0])]+' '+suffix[j]+' '
    j=j-1
elif e==2 :
    wordfd=wordfd+' '+convert(str[0:2])+' '+suffix[j]+' '
    j=j-1

j=(len(str)//3)-2
for i in range(e,len(str),3):
    wordf=convert(str[i:i+3])
    if i==len(str)-3 :
        wordfd=wordfd+wordf+' '
    else:
        wordfd=wordfd+wordf+' '+suffix[j]+' '
    j=j-1

print(wordfd)    
