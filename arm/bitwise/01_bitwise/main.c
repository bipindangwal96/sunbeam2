#include <stdio.h>

int main()
{
	int a = 10, b = 6, c;
	unsigned int d;

	c = a & b;
	printf("a & b = %d\n", c); // 2
	
	c = a | b;
	printf("a | b = %d\n", c); // 14

	c = a ^ b;
	printf("a ^ b = %d\n", c); // 12

	c = ~a;
	printf("~a = %x\n", c); // fffffff5

	a = 5;
	c = ~a + 1;
	printf("a = %d, 	c = %x, 	c = %d\n", a, c, c);

	b = 9;
	c = ~b;
	printf("b = %d, 	c = %x, 	c = %d\n", b, c, c);

	b = 6;
	c = b << 1;
	printf("b = %d,		c = %d\n", b, c);
	
	b = -6;
	c = b << 1;
	printf("b = %d,		c = %d\n", b, c);

	b = 6;
	d = 6;
	printf("b = %d,		b >> 1 = %d, 	d = %d, 	d >> 1 = %d\n", b, b>>1, d, d>>1);

	b = -6;
	d = -6;
	printf("b = %d,		b >> 1 = %d, 	d = %d, 	d >> 1 = %d\n", b, b>>1, d, d>>1);
	
	return 0;
}











