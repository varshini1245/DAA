#include<stdio.h>
#include<conio.h>
int main()
{
int n, i, j;
printf("n= ");
scanf("%d",&n);
for(i = 1; i <= n; i++)
{
for(j = n; j > i; j--)
{
printf(" ");
}
for(j = 1; j <= i; j++)
{
printf("%d ",j);
}
printf("\n");
}
return 0;
}
