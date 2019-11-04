#include<stdio.h>
enum color
{
	BLACK, RED, GREEN=5, YELLOW
	//0    1        5      6
}; // decl of enum
int main(void)
{
	enum color c;
	//enum color is user defined data type
	// c is variable of user defined data type enum color
	// c will take memory 4 bytes
	int no1; // int is a data type
	// no1 is variable of int data type
	/// no1 will take 4 bytes in memory
	printf("\n size of c=%d", sizeof(c));
	printf("\n size of enum color=%d", sizeof(enum color));

	printf("\n 0. Black 1. Red 5.Green 6. Yellow \n");
	printf("\n Enter Color::");
	//scanf("%d", &c); // way 1 scan using enum color variable c

	scanf("%d", &no1);
	//c= (enum color)no1; // way 2 scan int no1 and assign after type casting

	//way3 using switch case  and int no1
	switch(no1)
	{
		case 0: c=BLACK; break;
		case 1: c=RED; break;
		case 5: c=GREEN; break;
		case 6: c=YELLOW; break;
		default: c=7; break;
	}

	switch(c)
	{
		case BLACK: printf("\n Black color "); break;
		case RED: printf("\n Red color "); break;
		case GREEN: printf("\n Green color "); break;
		case YELLOW: printf("\n Yellow color "); break;
		default: printf("\n invalid color");break;
	}

	return 0;
}



