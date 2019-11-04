#include<stdio.h>
int main(void)
{
	int row, col;

	for(row=1; row<=10; row++)
	{
		for(col=1; col<=10; col++)
		{
			//printf("\n row=%d col=%d", row, col); // print row and col value
			//printf("%5d", row*col); // table
			printf("%5d", row+(col-1)*10);
		}
		//getchar();
		printf("\n");

	}
	return 0;
}

