#include <stdio.h>
#define SIZE 5
void ReadArray(int a[], int size);
void PrintArray(int *a, int size);
void SelectionSort(int a[], int size);
int main(void)
{
	int arr1[ SIZE ];

	printf("\n Enter Elements of array1 :: \n");
	ReadArray(arr1,SIZE);

	printf("\n Elements of Array1 :: ");
	PrintArray(arr1, SIZE);

	printf("\n Elements of Array after asc sort :: ");
	SelectionSort(arr1, SIZE);
	PrintArray(arr1, SIZE);

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

void SelectionSort(int a[], int size)
{
	int i, j, temp;

	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size;j++)
		{
			printf("\n a[%d]=%d a[%d]=%d\n", i, a[i], j, a[j]);
			//if(a[i]>a[j]) // asc
			if(a[i]<a[j]) // desc
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		if(i<size-1)
			printf("\n \t\t pass %d\n", i+1);
	}

	return;
}
