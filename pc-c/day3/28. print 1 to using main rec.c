#include<stdio.h>
//int no=1;
static int no=1;

int main(void)
{
	//static int no=1;
	//getchar();
	if(no>10)
		return 0;
	else
	{
		printf("\n %5d [%u]", no, &no);
		no++;
		main();
	}
	return 0;
}
