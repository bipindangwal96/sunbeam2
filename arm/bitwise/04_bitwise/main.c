#include <stdio.h>

#define BV(n) (1<<(n))

int main()
{
	int num = 12232, n = 7;
	// check if num is divisible by 2
	if( num & (1<<0) );
	if( num & BV(0) );

	// check if num is divisible by 4
	if( num & (1<<1 | 1<<0) );
	if( num & (BV(1) | BV(0)) );

	// check nth bit of num
	if( num & (1<<n) );
	if( num & BV(n) );

	// change nth bit of num to 1
	num = num | (1<<n);
	num |= (1<<n);
	num |= BV(n);
	
	// change nth bit of num to 0
	num = num & ~(1<<n);
	num &= ~(1<<n);
	num &= ~BV(n);

	// toggle nth bit of num
	num = num ^ (1<<n);
	num ^= (1<<n);
	num ^= BV(n);
	return 0;
}











