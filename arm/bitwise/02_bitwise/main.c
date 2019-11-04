#include <stdio.h>

void showbits(unsigned int num)
{
	unsigned int mask = 0x80000000; // 31st bit 1
	while(mask)
	{
		if(num & mask)
			putchar('1');
		else
			putchar('0');
		mask = mask >> 1;
	}
	putchar('\n');
}

int main()
{
	int num = 65;
	
	// check if number is even or odd.
	if(num & 1)
		printf("Odd Number.\n");
	else
		printf("Even Number.\n");

	// check if number is divisible by 4.
	if(num & 3)
		printf("Not divisible by 4.\n");
	else
		printf("Divisible by 4.\n");

	// show bits
	showbits(num);

	// find lower/equal multiple of 4.
	// 16->16, 15->12, 14->12, 13->12, 12->12.
	printf("lower multiple of %d is %d\n", num, num & ~3);
	
	// find upper/equal multiple of 4.
	// 12->12, 13->16, 14->16, 15->16, 16->16.
	printf("upper multiple of %d is %d\n", num, (num+3) & ~3);

	return 0;
}











