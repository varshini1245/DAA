#include<stdio.h>
int fact(int n)
{
	if(n==0 || n==1)
	{
	return 1;
	}
	else
	{
	return n*fact(n-1);
	}
}
	int main()
	{
		int i,d;
		printf("Enter the value: ");
		scanf("%d",&i);
		d=fact(i);
		printf("Factorial: %d ",d);
	}
