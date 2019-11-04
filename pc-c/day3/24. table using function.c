#include<stdio.h>
void table(int n);
int table_no(int n, int c);
int main(void)
{
	int no, i;
	printf("\n Enter No :: ");
	scanf("%d", &no);

	table(no); // function call

	printf("\n table of %d is printed in main \n", no);
	for(i=1; i<=10; i++)
	{
		printf("\n %d * %d = %d", no, i, table_no(no, i));
	}

	return 0;
}
int table_no(int n, int c)
{
	return n*c;
}
void table(int n)
{
	int counter;
	printf("\n print table of %d in function :: \n", n);
	for(counter=1; counter<=10; counter++)
	{
		printf("\n %d * %d = %d ", n, counter, n*counter);
	}
	return ;
}
// if u dont have return any value return type should be void
// void nothing
