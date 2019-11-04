#include<stdio.h>
void table(int n);
int main(void)
{
	int no;
	printf("\n Enter No :: ");
	scanf("%d", &no);

	table(no); // function call
	return 0;
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
