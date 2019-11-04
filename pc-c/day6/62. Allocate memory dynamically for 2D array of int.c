
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int row , col,r,c, **ptr=NULL;
	printf("\n Enter how many rows u want :: ");
	scanf("%d", &row);
	printf("\n Enter how many cols u want :: ");
	scanf("%d", &col);
	// allocate memory dynamically
	ptr= (int**)malloc(sizeof(int*)*row);
	if(ptr==NULL)
		printf("\n unable to allocate memory");
	else
	{
		for(r=0; r<row; r++)
		{
			ptr[r]= (int*)malloc(sizeof(int)*col);
		}

		// accept input
		for(r=0; r<row; r++)
		{
			for(c=0; c<col; c++)
			{
				printf("ptr[%d][%d]", r,c);
				//scanf("%d", &ptr[r][c]);
				scanf("%d", (*(ptr+r)+c));
			}
		}

		// print output
		printf("\n &ptr=%u ptr=%u \n", &ptr, ptr);
		for(r=0; r<row; r++)
		{
			printf("\t\t &ptr[%d]=%u ptr[%d]=%u \n", r, &ptr[r], r, ptr[r]);
			for(c=0; c<col; c++)
			{
				//printf("\t %d [%u]", ptr[r][c], &ptr[r][c]);
				printf("\t %d [%u]", *(*(ptr+r)+c) , (*(ptr+r)+c));
			}
			printf("\n");
		}
		for(r=0; r<row;r++)
		{
			free(ptr[r]);
			ptr[r]=NULL;
		}
		free(ptr);
		ptr=NULL;
		printf("\n Memory is freed");

	}


	return EXIT_SUCCESS;

}
