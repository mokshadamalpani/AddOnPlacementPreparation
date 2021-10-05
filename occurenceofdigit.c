#include <stdio.h>

void occ(int *a,int n)
{
	int lastdig;
	while(n != 0)
	{
		lastdig=n%10;
		n/=10;
		a[lastdig]++;
	}
}

int main(void)
{
	long int n=0;
	int a[10];
	int i;
	printf("\n Enter any Number :\n");
	scanf("%ld",&n);
	for(i=0;i<10;i++)
	{	
		//initialzing array to zero
		a[i]=0;
	}
	occ(a,n);
	printf("Occurence of each digit in %ld is :\n",n);
	for(i=0;i<10;i++)
	{
		printf("Occurence of %d = %d \n",i,a[i]);
	}
}
