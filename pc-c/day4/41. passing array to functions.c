#include <stdio.h>
#define SIZE 5
// array notation
  void ReadArray(int a[], int size);
//void ReadArray(int a[SIZE], int size);
// pointer notation
  void PrintArray(int *a, int size);
int main(void)
{
	int arr1[ SIZE ], arr2[ 7 ];

	printf("\n Enter Elements of array1 :: \n");
	ReadArray(arr1,SIZE);

	printf("\n Elements of Array1 :: ");
	PrintArray(arr1, SIZE);

	printf("\n Enter Elements of array2 :: \n");
	ReadArray(arr2,7);

	printf("\n Elements of Array2 :: ");
	PrintArray(arr2, 7);

     //arr1++; // lvalue error
	printf("\n size of arr1=%d", sizeof(arr1));
	printf("\n size of arr2=%d", sizeof(arr2));

	//arr1=arr2; //error
	arr1[0]=arr2[0]; //allowed

	return 0;
}
void ReadArray(int a[], int size)
{
	int index;

	for(index=0; index<size; ++index)
	{
		printf("\n a[ %d ] :: ", index);
		//scanf("%d", &a[index]); // array notation
		  scanf("%d", &index[a]);
		//scanf("%d", (a+index)); // pointer notation
		//scanf("%d", (index+a));
	}
	a++; // allowed in function as a in pointer
	printf("\n size of a=%d\n", sizeof(a));
	return;
}
void PrintArray(int *a, int size)
{
	int index;
	for(index=0; index<size ; ++index)
	{
		// array notation
		//printf("\n a[%d] %6d [%u]", index, a[index], &a[index]);
		  printf("\n a[%d] %6d [%u]", index, index[a], &index[a]);
		//pointer notation
		 //printf("\n *(a+%d) %6d [%u]", index, *(a+index), (a+index));
		//printf("\n *(%d+a) %6d [%u]", index, *(index+a), (index+a));
	}
	return;
}
