#include"../include/fact.h"
// function defination
int factorial(int n)
{
	int i, fact;
	for(i=fact=1; i<=n; i++)
	{
		fact*=i; // fact= fact*i;
	}
	return fact;
}
