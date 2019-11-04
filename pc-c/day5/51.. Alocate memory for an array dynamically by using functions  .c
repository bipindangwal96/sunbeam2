#include <stdio.h>
#include <stdlib.h>

int* AllocateMemoryForArray(int size);
void ReadArray(int *a, int size);
void PrintArray(const int *a, int size);
void FreeArray(int *a);

int main(void)
{
	int index, *ptr, no;
	printf("\n Enter How many elements you want :: \n");
	scanf("%d", &no);

	ptr=AllocateMemoryForArray(no);
	if(ptr==NULL)
		printf("\n unable to allocate memory");
	else
	{
		printf("\n Enter elements of array :: ");
		ReadArray(ptr, no);

		printf("\n Elements of array are :: \n");
		PrintArray(ptr,no );

		FreeArray(ptr);
	}
	return EXIT_SUCCESS;
}
void FreeArray(int *a)
{
	free(a);
	a=NULL;
	printf("\n Memory is freed\n");
	return;
}
void ReadArray(int *a, int size)
{
	int index;
	for(index=0; index<size; index++)
	{
		printf("\n a[%d] :: ", index);
		//scanf("%d", (a+index)); // pointer notations
		//scanf("%d", (index+a));
		//scanf("%d", &a[index]); // array notation
		scanf("%d", &index[a]);
	}
	return;
}
void PrintArray(const int *a, int size)
{
	int index;
	printf("\n a=%u &a=%u\n", a, &a);
	for(index=0; index<size; ++index)
	{
		// pointer notations
		//printf("\n *(a+%d) %5d [%u]", index, *(a+index), (a+index));
	   // printf("\n *(a+%d) %5d [%u]", index, *(index+a), (index+a));
		// array notation
		//printf("\n a[%d]  %d [%u]", index, a[index], &a[index]);
		printf("\n %d[a]  %5d [%u]", index, index[a], &index[a]);
	}
	return;
}
int* AllocateMemoryForArray(int size)
{
	int *a=NULL;
	a= (int*)malloc(sizeof(int)*size);
	return a;
}
// to compile --->>>  gcc -o demo7.out demo7.c
// to check memeory leakage --->>> valgrind ./demo7.out




