#include <stdio.h>
#define ROW 2
#define COL 2
//void ReadMatrix(int m[ROW][COL], int row, int col);
void ReadMatrix(int m[][COL], int row, int col);
void PrintMatrix(const int m[][COL], int row, int col);
void MatrixAddition(int m1[][COL], int m2[][COL],int res[][COL], int row, int col);
int main(void)
{
	int mat1[ROW][COL],mat2[ROW][COL],ans[ROW][COL]={0};

	printf("\nEnter elements of matrix1 ::  \n");
	ReadMatrix(mat1, ROW, COL);

	printf("\n Elements of matrix1 :: \n");
	PrintMatrix(mat1, ROW, COL);

	printf("\nEnter elements of matrix2 ::  \n");
	ReadMatrix(mat2, ROW, COL);

	printf("\n Elements of matrix2 :: \n");
	PrintMatrix(mat2, ROW, COL);

	printf("\n matrix addition :\n");
	MatrixAddition(mat1, mat2,ans, ROW, COL);
	PrintMatrix(ans, ROW, COL);

	return 0;
}
void MatrixAddition(int m1[][COL], int m2[][COL],int res[][COL], int row, int col)
{
	int r,c;
	for(r=0; r<row; r++)
	{
		for(c=0; c<col; c++)
		{
			//res[r][c]= m1[r][c]+ m2[r][c];
			*(*(res+r)+c)= *(*(m1+r)+c) + *(*(m2+r)+c);
		}
	}
	return;
}
void ReadMatrix(int m[][COL], int row, int col)
{
	int r,c;
	for(r=0; r<row; r++)
	{
		for(c=0; c<col; c++)
		{
			printf(" m[%d][%d]",r,c );
			//scanf("%d", &m[r][c]);
			scanf("%d", (*(m+r)+c) );
		}
	}
	return;
}
void PrintMatrix(const int m[][COL], int row, int col)
{
	int r,c;
	for(r=0; r<row; r++)
	{
		for(c=0; c<col; c++)
		{
			//printf("  %5d  [ %u ] ", m[r][c], &m[r][c]);
			printf("  %5d  [ %u ] ", *(*(m+r)+c), (*(m+r)+c));
		}
		printf("\n");
	}
	return;
}
// a[i]== *(a+i)   //1D
// a[i][j] ==  *(*(a+i)+j) //2D
// a[i][j][k] == *(*(*(a+i)+j)+k) //3D

