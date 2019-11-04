#include<stdio.h>
int sum(int no);
int main(void)
{
	int a=5, ans=0;
	ans= sum(a);
	printf("\n ans=%d", ans);
	return 0;
}
int sum(int no)
{
	int add=0;
	//printf("\n no=%d [%u]", no, &no);
	//getchar();
	if(no==1)
	{
		add=1;
		printf("\nno=%d [%u] ans=%d [%u]", no, &no, add, &add);
		return 1;
	}
	else
	{
		add=no+ sum(no-1);
		printf("\nno=%d [%u] ans=%d [%u]", no, &no, add, &add);
		return add;
	}
}

