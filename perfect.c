#include <stdio.h>

int main(void)
{
	int n,i,p,sum;
	printf("Enter Number :\n");
	scanf("%d",&n);
	printf("All perfect number between 1 to %d are :\n",n);
	for(i=1;i<=n;i++)
	{
		p=1;
		sum=0;
		while(p<=(i/2))
		{
			if(i%p==0)
				sum+=p;
			p++;
		}	
		if(sum==i)
		{
			printf("%d ,",i);
		}
	}
}
