
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}
void printPrime(int n)
{
	for (int i = 2; i <= n; i++)
		if (isPrime(i))
			printf("%d  ",i);
}


int main()
{
	int n ;
	printf("enter:");
	scanf("%d",&n);
	printPrime(n);
}

