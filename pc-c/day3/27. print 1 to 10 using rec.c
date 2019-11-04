#include<stdio.h>
//int no=1;
static int no=1;
void fun();
int main(void)
{
	fun();
	return 0;
}
void fun()
{
	//static int no=1;
	//getchar();
	if(no>10)
		return;
	else
	{
		printf("\n %5d [%u]", no, &no);
		no++;
		fun();
	}
}
