#include <stdio.h>
#include"../include/fact.h"
int main(void)
{
	int no=7, ans=0;

	ans= factorial(no); // function call

	printf("\n %d != %d ", no, ans);

	return 0;
}
