#include <stdio.h>
int main(void)
{
	int n1=2, n2=4;
	int sum(int no1, int no2);
	int (*funptr)(int no1, int no2);

	funptr=sum;
	printf("\n using sum fun = %d", sum(n1, n2));

	printf("\n using fun  ptr= %d", (*funptr)(n1, n2));
	printf("\n using fun  ptr= %d", funptr(n1, n2));
	return 0;
}
int sum(int no1, int no2)
{
	return no1+no2;
}
