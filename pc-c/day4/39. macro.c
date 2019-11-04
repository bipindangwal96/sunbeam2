#include <stdio.h>
#define sq(a) a*a
#define sq1(a) (a)*(a)
int square(int a);
int main(void)
{
	int x =5, y=0;
	y= sq(x); //y= x*x ; // y=5*5;
	printf("\n x=%d y=%d", x, y);

	y= sq(x+x);// y= x+x*x+x;// y=5+5*5+5;// y=5+25+5;
	printf("\n x=%d y=%d", x, y);

	y= 25/sq(x); // y= 25/x*x; // y= 25/5*5;; y=5*5 ; y=25
	printf("\n x=%d y=%d", x, y);

	y= sq1(x+x); // y=(x+x)*(x+x); y=(5+5)*(5+5) // y=10*10//100
	printf("\n x=%d y=%d", x, y);

	y= square(x);
	printf("\n using function x=%d y=%d", x, y);
	return 0;
}
int square(int a)
{
	return a*a;
}
