#include<stdio.h>
int main(void)
{
	int no, counter;

	printf("\n Enter No :: ");
	scanf("%d", &no);

	// print 1 to no
	/*for(counter=1; counter<=no; counter++)
	{
		printf("%5d", counter);
	}*/

	// print  no to 1
	/*for(counter=no; counter>0; counter--)
	{
		printf("%5d", counter);
	}*/

	// print 1 to no
	/*counter=1; // init
	for(;;)
	{
		printf("%5d", counter);
		counter++; // increment / decrement
		if(counter>no)
			break;
	}*/

	// print last value of counter

	for(counter=1; counter<=no; counter++)
	;
	{
		printf("%5d", counter);
	}



	return 0;
}


