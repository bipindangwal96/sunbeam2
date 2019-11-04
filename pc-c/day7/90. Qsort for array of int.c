#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
void ReadArray(int a[], int size);
void PrintArray(int *a, int size);
int asc(const void *ptr1, const void *ptr2); // 1. write fun  asc and desc
int desc(const void *ptr1, const void *ptr2);

int main(void)
{
	int arr1[ SIZE ];
	int (*funptr)(const void *ptr1, const void *ptr2);
	// 2. delc funptr to store address of asc or desc

	printf("\n Enter Elements of array1 :: \n");
	ReadArray(arr1,SIZE);

	printf("\n Elements of Array1 :: ");
	PrintArray(arr1, SIZE);

	printf("\n Elements of Array after asc sort :: ");
	funptr=asc; // 4 store address of fun into fun ptr
	qsort(arr1,SIZE, sizeof(int), funptr);
	PrintArray(arr1, SIZE);

	printf("\n Elements of Array after desc sort :: ");
	funptr=desc;// 4 store address of fun into fun ptr
	qsort(arr1, SIZE,sizeof(int), funptr);
	PrintArray(arr1, SIZE);

	return 0;
}
int asc(const void *ptr1, const void *ptr2)
{
	printf("\n *ptr1=%d *ptr2=%d", *(int*)ptr1, *(int*)ptr2);
	int *p1= (int*)ptr1;
	int *p2= (int*)ptr2;
	return *p1-*p2;
}
int desc(const void *ptr1, const void *ptr2)
{
	int *p1= (int*)ptr1;
	int *p2= (int*)ptr2;
	return *p2-*p1;
}


void ReadArray(int a[], int size)
{
	int index;

	for(index=0; index<size; ++index)
	{
		printf("\n a[ %d ] :: ", index);
		scanf("%d", &index[a]);
	}
	return;
}
void PrintArray(int *a, int size)
{
	int index;
	for(index=0; index<size ; ++index)
	{
		printf("\n a[%d] %6d [%u]", index, index[a], &index[a]);
	}
	return;
}

