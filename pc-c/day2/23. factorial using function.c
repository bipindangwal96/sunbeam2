#include<stdio.h>
int factorial (int n);
int main(void)
{
	int no, ans;
	printf("\n Enter No :: ");
	scanf("%d", &no);

	ans= factorial(no);// no is actual argument
	printf("\n %d ! = %d",no, ans);

	return 0;
}
int factorial (int n)
{
	int counter, fact;
	for(counter=fact=1;counter<=n; ++counter )
	{
		fact= fact*counter;
	}
	return fact;
}
