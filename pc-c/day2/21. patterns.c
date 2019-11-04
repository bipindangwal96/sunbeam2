#include<stdio.h>
int main(void)
{
	int row, col, no, counter=1;
	printf("\n how many rows u want :: ");
	scanf("%d", &no);

	for(row=counter=1; row<=no; row++)
	{
		for(col=1; col<=row; col++)
		{
			//printf("%5d", row); // print rows
			//printf("%5d", col); // print cols
			//printf("%5c", col+64); // print cols
			//printf("%5c", row+64); // print rows
			//printf(" * ");

			printf("%4d", counter++);
		}
		//getchar();
		printf("\n"); // goto next line

	}
	return 0;
}

