#include<stdio.h>
int main(void)
{
	int no, counter;

	printf("\n Enter No :: ");
	scanf("%d", &no);

	// print 1 to no
	/*counter=0;
	while(counter<no)
	{
		counter++;
		printf("%5d",counter);
	}*/
	

	// print no to 1
/*	counter=no;
	while(counter>0)
	{
		printf("%5d",counter);
		counter--;
	}*/

	// print 1 to no
	/*counter=0;
	while(1)
	{
		counter++;

		printf("%5d",counter);
		if(counter>=no)
			break; // go out of loop
		if(counter%10==0)
					printf("\n");
	}*/


	// print 1 to no
	/*counter=0;
	while(100) // infinite loop stop by terminate button
	{
		counter++;
		printf("\n%5d",counter);
	}*/


	// print 1 to no
	counter=0;
	while(counter<no);  // infinte loop
	{
		counter++;
		printf("\n%d",counter);
	}

	return 0;
}


