#include <stdio.h>
#include "add.h"
#include "subtract.h"
#include "multiply.h"

int main()
{
	int res;
	res = add(23, 5);
	printf("add result : %d\n", res);
	res = subtract(23, 5);
	printf("subtract result : %d\n", res);
	res = multiply(23, 5);
	printf("multiply result : %d\n", res);
	return 0;
}

