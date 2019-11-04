#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	{
	// pre increment
	int x=5, y=0;
	// increment value of x by 1 then assigned it to y
	y=++x;
	printf(" \n x=%d y=%d", x, y);
	}
	{
	   // post increment
		int x=5, y=0;
		// assigned value of x to y then increment value of x by 1
		y=x++;
		printf(" \n x=%d y=%d", x, y);
	}
	{
		 // post decrement
			int x=5, y=0;
		// assigned value of x to y then decrement value of x by 1
			y=x--;
			printf(" \n x=%d y=%d", x, y);
	}
	{
		// pre decrement
		int x=5, y=0;
		// decrement value of x by 1 then assigned it to y
		y=--x;
		printf(" \n x=%d y=%d", x, y);
	}
	{
		//printf("\n %d", ++5);// error lvalue required
	}
	{
		int x=5 ,y=2;
		//printf("\n %d",++(x+y) ); // error
		printf("\nx=%d", ++(x)); // allowed
	}
	return 0;
}
