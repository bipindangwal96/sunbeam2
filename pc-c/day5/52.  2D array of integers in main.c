#include <stdio.h>
#define ROW 3
#define COL 3

int main(void)
{
	//int mat1[ROW][COL]={{1,2}, {3,4}, {5,6}}; // allowed
	//int mat2[   ][COL]={{1,2}, {3,4}, {5,6}}; // allowed
	//int mat3[ROW][   ]={{1,2}, {3,4}, {5,6}}; // not allowed
	//int mat4[  ][ ]={{1,2}, {3,4}, {5,6}}; // not allowed

	int mat[ROW][COL], r,c;

	printf("\nEnter elements of matrix ::  \n");
	for(r=0; r<ROW; r++)
	{
		for(c=0; c<COL; c++)
		{
			printf(" mat[%d][%d]",r,c );
			//scanf("%d", &mat[r][c]);
			scanf("%d", (*(mat+r)+c) );
		}
	}

	printf("\n elements of matrix :: \n");
	for(r=0; r<ROW; r++)
	{
		for(c=0; c<COL; c++)
		{
			//printf("  %5d  [ %u ] ", mat[r][c], &mat[r][c]);
			printf("  %5d  [ %u ] ", *(*(mat+r)+c), (*(mat+r)+c));
		}
		printf("\n");
	}

	return 0;
}
