#include <stdio.h>
int main(void)
{
	int a=1000;
	float f=10.2f;
	char ch='A';

	void *ptr=NULL;

	ptr=&a; // store address of int variable a into void pointer ptr
	//printf("\n *ptr=%d", *ptr);
	//error we can display data using void pointer

	printf("\n *ptr=%d", *(int*)ptr);
	//allowed after type casting that pointer with that data type pointer whose address store in void pointer



	ptr=&f;
	//printf("\n *ptr=%f", *ptr);
	printf("\n *ptr=%f", *(float*)ptr);


	ptr=&ch;
	//printf("\n *ptr=%f", *ptr);
	printf("\n *ptr=%c", *(char*)ptr);

	printf("\n ptr=%u", ptr);
	ptr++; //should give error according ansi c
	// in gcc scale factor of void pointer is consider as 1
	printf("\n ptr=%u", ptr);
	return 0;
}
