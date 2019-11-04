#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
void PrintArray(char *a, int size);
int asc(const void *ptr1, const void *ptr2); // 1. write fun  asc and desc
int desc(const void *ptr1, const void *ptr2);

int main(void)
{
	char arr1[ SIZE ]={'a','r','c','b', 'd'};
	int (*funptr)(const void *ptr1, const void *ptr2);
	// 2. delc funptr to store address of asc or desc

	printf("\n Elements of Array1 :: ");
	PrintArray(arr1, SIZE);

	printf("\n Elements of Array after asc sort :: ");
	funptr=asc; // 4 store address of fun into fun ptr
	qsort(arr1,SIZE, sizeof(char), funptr);
	PrintArray(arr1, SIZE);

	printf("\n Elements of Array after desc sort :: ");
	funptr=desc;// 4 store address of fun into fun ptr
	qsort(arr1, SIZE,sizeof(char), funptr);
	PrintArray(arr1, SIZE);

	return 0;
}
int asc(const void *ptr1, const void *ptr2)
{

	char *p1= (char*)ptr1;
	char *p2= (char*)ptr2;
	return *p1-*p2;
}
int desc(const void *ptr1, const void *ptr2)
{
	char *p1= (char*)ptr1;
	char *p2= (char*)ptr2;
	return *p2-*p1;
}

void PrintArray(char *a, int size)
{
	int index;
	for(index=0; index<size ; ++index)
	{
		
		  printf("\n a[%d] %6c [%u]", index, index[a], &index[a]);
		
	}
	return;
}

