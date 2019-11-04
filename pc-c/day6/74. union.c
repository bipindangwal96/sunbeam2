#include <stdio.h>
#include <stdlib.h>

union test
{
	char name[2];
	short int  no;
};
typedef union test TEST;
int main(void)
{
	TEST t;	//union test t;
	t.name[0]='a' ;//'A';
	t.name[1]='b';//'B';
	// or
	//t.no=16961;

	printf("\n size of t =%d", sizeof(t));
	printf("\n t.name[0]=%c", t.name[0]);
	printf("\n t.name[1]=%c", t.name[1]);
	printf("\n t.no =%d", t.no);

	return EXIT_SUCCESS;
}


/*
A	65	01000001
B	66	01000010

16961	0100001001000001
BA	    0100001001000001

_______________________________________
*/
/*
a	97     01100001
b	98     01100010

25185  0110001001100001
ba     0110001001100001

*/
