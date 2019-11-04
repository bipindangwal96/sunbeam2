
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int no1, no2, ans;
	char op;

	printf("\n Enter no1 :: ");
	scanf("%d", &no1);

	printf("\n Enter op :: ");
	scanf("%*c%c", &op);

	printf("\n Enter no2 :: ");
	scanf("%d", &no2);

	
	// using if
	/*if(op=='+')
		ans=no1+no2;
	if (op=='-')
		 ans=no1-no2;
	if (op=='*')
		ans=no1*no2;
	if (op=='/')
		ans=no1/no2;
	*/

	// using if else
	if(op=='+')
	{
		ans=no1+no2;
		//break; not allowed in if only
	}
	else if (op=='-')
	{
		ans=no1-no2;
	}
	else if (op=='*')
		ans=no1*no2;
	else if (op=='/')
	{
		if(no2==0)
		{
			printf("\n divide by zero error");
			return 0;
		}
		else
			ans=no1/no2;
	}
	else
	{
		printf("\n invalid operator");
		exit(0);//return 0;
	}

	printf("\n %d %c %d=%d", no1, op, no2, ans);

	return 0;
}
