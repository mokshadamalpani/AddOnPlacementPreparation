
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tree
{
	struct tree *right;
	char word[20];
	int len;
	struct tree *left;
};
struct tree * create(char word[10])
{
	struct tree *newnode=(struct tree *)malloc(sizeof(struct tree));
	newnode->left=NULL;
	newnode->right=NULL;
	strcpy(newnode->word,word);
	newnode->len=strlen(word);
	return newnode;
}

void insert(struct tree *newnn,struct tree **root)
{
	if(*root==NULL)
	{
		*root=newnn;
	}
	else
	{
	    struct tree *parent=NULL;
	    struct tree *current=*root;
	    while(1)
	    {
	        parent=current;
	        if(newnn->len<current->len)
	        {
	            current=current->left;
	            if(current==NULL)
	            {
	                parent->left=newnn;
	                return;
	            }
	        }
	        else
	        {
	            current=current->right;
	            if(current==NULL)
	            {
	                parent->right=newnn;
	                return;
	            }
	            
	        }
	    }
	}
}
		
void display(struct tree *root)
{
	if(root==NULL)
	{
	    return;
	}
	printf("%s\t",root->word);
	//printf("%d",root->len);
	printf("\n");
	display(root->right);
	display(root->left);
}

int matching(char temp[10],int pos[10],char known[10],int cnt_letter)
{
    int index;
    for(index=0;index<cnt_letter;index++)
    {
        if(temp[pos[index]-1]!=known[index])
        return 0;
    }
    return 1;
}

void search(int len,char known[10],struct tree *root,int pos[10],int cnt_letter)
{
    char temp[10];
    if(root==NULL)
    {
        return;
    }
    if(root->len==len)
    {
        strcpy(temp,root->word);
        if(matching(temp,pos,known,cnt_letter))
        {
            printf("%s\n",root->word);
        }
    }
    if(len>=root->len)
    {
        search(len,known,root->right,pos,cnt_letter);
    }
    else
    {
        search(len,known,root->left,pos,cnt_letter);
    }
    
}

void main()
{
	char words[25][15]={"apple","start","bat","banana","basic","come","came","daily","egg","congrats","monkey","south","dogs","actor","pineapple","mostly","doors","watch","roof","walks","root","flower","flasks","bucket","steps"};
  char letters[10];
	int size=sizeof(words) / sizeof(words[0]),word,length_word,ch,pos[10],cnt_letter;
	struct tree *temp=NULL,*root=NULL;
	for(word=0;word<size;word++)
	{
		temp=create(words[word]);
		insert(temp,&root);
	}
	printf("Press 1 to See The Dictionary : ");
	scanf("%d",&ch);
	if(ch==1)
	{
		display(root);
	}
	printf("\nEnter Length of Word : ");
	scanf("%d",&length_word);
	printf("\n Enter Number of charaters Do Know From That Word : ");
	scanf("%d",&cnt_letter);
	for(word=0;word<cnt_letter;word++)
	{
      printf("\nEnter a Charater Which You Know From Your Word : ");
      scanf("%c",&letters[word]);
      scanf("%c",&letters[word]);
	    printf("\nEnter Position of That Charater : ");
	    scanf("%d",&pos[word]);
	}
	    search(length_word,letters,root,pos,cnt_letter);
	    printf("\nSearching Finished !!!");
	
}
