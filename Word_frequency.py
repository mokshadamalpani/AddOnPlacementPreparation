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
    
for Keys in dic:
    print("Frequency of ",Keys,end="")
    print(":",end="")
    print(dic[Keys],end="")
    print()
    

