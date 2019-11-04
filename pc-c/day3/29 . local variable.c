#include<stdio.h>

int no1=100; // defination of global variable (memory)
int main(void)
{
	{ // block1
		int no1=10; // decl and defination of local variable
		printf("\n no1=%d [%u] in block 1 local", no1, &no1);

		{ // block2
				int no1=50;
				printf("\n no1=%d [%u] in block 2 local ", no1, &no1);
		}
	}
	printf("\n no1=%d [%u] in main global variable", no1, &no1);
	return 0;
}


extern int no1;// decl of global variable
