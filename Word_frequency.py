def count(word):
    if word[-1]=='.':
        word=word[0:len(word)-1]
    if word in dic:
        dic[word]+=1
    else:
        dic.update({word:1})
    
sentence=input("Enter data you want")
dic={}
list=sentence.split()
for word in list:
    count(word)

while(1):
    key=input("Enter key which you want to search the occurences")
    if key=="stop":
        break;
    else:
        for Keys in dic:
            if Keys==key:
                flag=1
                print("Frequency of ",Keys,":",end="")
                print(dic[Keys],end="")
                print()
                break
            else:
                flag=0

        if flag==0:
            print("Key Not Found")

    
