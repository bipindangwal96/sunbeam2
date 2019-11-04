#include <stdio.h>
#define SIZE 5
void ReadArray(int a[], int size);
void PrintArray(int *a, int size);
// 3. pass function pointer as a parameter to function
void SelectionSort(int a[], int size, int (*fp)(int no1, int no2) );
int asc(int n1, int n2); // 1. write fun  asc and desc
int desc(int n1, int n2);

int main(void)
{
	int arr1[ SIZE ];
	int (*funptr)(int no1, int no2);
	// 2. delc funptr to store address of asc or desc

	printf("\n Enter Elements of array1 :: \n");
	ReadArray(arr1,SIZE);

	printf("\n Elements of Array1 :: ");
	PrintArray(arr1, SIZE);

	printf("\n Elements of Array after asc sort :: ");
	funptr=asc; //4. store address if asc fun in function pointer
	SelectionSort(arr1, SIZE,funptr);
	PrintArray(arr1, SIZE);

	printf("\n Elements of Array after desc sort :: ");
	funptr=desc;
	SelectionSort(arr1, SIZE,funptr);
	PrintArray(arr1, SIZE);

	return 0;
}
int asc(int n1, int n2)
{
	return n1-n2;
}
int desc(int n1, int n2)
{
	return n2-n1;
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

void SelectionSort(int a[], int size, int (*fp)(int no1, int no2))
{
	int i, j, temp;

	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size;j++)
		{
			printf("\n a[%d]=%d a[%d]=%d\n", i, a[i], j, a[j]);
			if( fp(a[i],a[j])>0)
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
