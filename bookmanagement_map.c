#include <stdio.h>
#include <stdlib.h>
struct book
{
	int id;
  char name[10];
	struct book *next;
};
int cnt=0;
int menu()
{
	 int ch;
	 printf("\n press 1 for create");
	 printf("\n press 2 for insert");
	 printf("\n press 3 for delete");
   	 printf("\n press 4 for Search");
	 printf("\n press 5 for display");
	 printf("\n enter your choice");
	 scanf("%d",&ch);
	 return ch;
}

void create(struct book **head,struct book **last,int n)
{
	 int i;
	 struct book *newnode;
	 for(i=0;i<n;i++)
	  {
	  	 newnode=(struct book *)malloc(sizeof(struct book));
	  	 printf("\n Enter a book Details");
       printf("\n Enter a book id");
       scanf("%d",&newnode->id);
       printf("\n Enter a book name");
	  	 scanf("%s",newnode->name);
		   newnode->next=NULL;
		 
		 if(*head==NULL)
		  {
		  	  *head=*last=newnode;
		  }
		  else
		   { 
           (*last)->next=newnode;
            *last=newnode;
		    }  
         cnt+=1;  
	  }
   
}
  
 void display(struct book *head)
 {
 	  if(head==NULL)
 	  {
 	  	  printf("\n list is empty");
 	  }
 	  else
 	   {
 	   	  struct book *temp=head;
 	   	  while(temp!=NULL)
 	   	  {
 	   	  	 printf(" %d %s",temp->id,temp->name);
 	   	  	 temp=temp->next;
           printf("\n") ; 
		  }
		}
} 
 
void insert(struct book **head,struct book **last,int pos)
{
    cnt+=1;
	  struct book *newnode;
	  newnode=(struct book *)malloc(sizeof(struct book));
	  int i;
	  printf("\n enter data which u want to insert");
	  printf("\n Enter a book Details");
    printf("\n Enter a book id");
    scanf("%d",&newnode->id);
    printf("\n Enter a book name");
	  scanf("%s",newnode->name);
	  newnode->next=NULL;
	  if(*head==NULL)
	  {
	  	*head=*last=newnode;
	  }
	  else
	  {
	  if(pos==1)
	   {
	   	  newnode->next=*head;
	   	  *head=newnode;
	   }
	   else
	   {
	   	 struct book *temp;
	   	 for(temp=*head,i=1;temp->next!=NULL && i<pos-1;temp=temp->next,i++);
	   	  
	   	     if((pos-1)<=i)
	   	     {
	   	  	  newnode->next=temp->next;
	   	  	  temp->next=newnode;
	   	  	  if(temp==*last)
	   	  	   {
	   	  	   	  *last=newnode;
	   	  	   }
	   	     }
	   	  	   else
	   	  	   {
	   	  	   	  printf("\n invalid position");
	   	  	   }
	   }
   }
} 
void delete(struct book **head,struct book **last,int pos)
{
	 struct book *temp=*head;
	 int i;
	  if(*head==NULL)
	  {
	  	  printf("\n list is empty");
	  }
	  else
	  {
	  	 if(pos==1)
	  	 {
	  	 	*head=temp->next;
	  	 	free(temp);
	  	 	return;
	  	 }
	  	 else
	  	 {
	  	 	 for(temp=*head,i=1;temp->next!=NULL && i<pos-1;temp=temp->next,i++);
          struct book *cur=temp->next;
          printf("%d",cnt);
	  	 	  if(pos<=cnt)
	  	 	  {
	  	 	    if(cur==*last)
	  	 	    {
               *last=temp;
			       }
			      temp->next=cur->next;
			      free(cur);
		      }
		      else
		       printf("\n invalid position");
			  }
	  }
 } 

 void Search(struct book *head,int pos)
 {
    int flag=0;
    struct book *temp=head;
    if(head==NULL)
 	  {
 	  	  printf("\n list is empty");
 	  }
 	  else
 	   {
 	   	  while(temp!=NULL)
 	   	  {  
            if(pos==temp->id)
            {
 	   	  	    printf("{%d :%s} is key Value Pair Present",temp->id,temp->name);
                flag=1;
            } 
 	   	  	 temp=temp->next;
           printf("\n") ; 
		    }
        if(flag==0)
          printf("No value is present for %d key",temp->id);
		}
 }
int main()
{
	  int ch,n,pos;
	  struct book *head=NULL;
	  struct book *last=NULL;
	  while((ch=menu())!=0)
	   {
	   	     if(ch==1)
	   	      { 
	   	    	 printf("\n enter how many node u want add in linked list");
	   	    	 scanf("%d",&n);
	   	    	 create(&head,&last,n);
	   	      }
	   	     else if(ch==5)
	   	      {
	   	     	 display(head);
	   	      }
	   	      else if(ch==2)
	   	      {
	   	         printf("\n enter a position where u want add");
				 scanf("%d",&pos);      	 
	   	      	 insert(&head,&last,pos);
		      }
		      else if(ch==3)
		      {
		      	  printf("\n enter a position which u want to delete");
		      	  scanf("%d",&pos);
		      	  delete(&head,&last,pos);
			  }
        else if(ch==4)
		      {
		      	  printf("\n enter id whose value you want");
		      	  scanf("%d",&pos);
		      	  Search(head,pos);
			  }
		} 
}
