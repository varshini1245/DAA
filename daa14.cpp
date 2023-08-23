#include<stdio.h>
int main()
{
	char s[50];
	int c=0;
	printf("Enter the string: ");
	gets(s);
	while(s[c]!='\0'){
		
		c++;
	}
	printf("the count : %d",c);
	return 0;
}
