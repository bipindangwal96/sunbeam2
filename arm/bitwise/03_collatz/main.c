#include <stdio.h>

int main()
{
	int n = 7;
	/*
	while(n != 1)
	{
		printf("%d, ", n);
		if(n % 2 == 1)
			n = n * 3 + 1;
		else
			n = n / 2;
	}
	printf("1.\n");
	*/

	while(n - 1)
	{
		printf("%d, ", n);
		if(n & 1)
			n = (n<<1) + n + 1;
		else
			n = n >> 1;	
	}
	printf("1.\n");
	return 0;
}











