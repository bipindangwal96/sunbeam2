#include <stdio.h>
#define SIZE 5
int main( void )
{
	int arr[ SIZE ], index;
	//int arr[  ]= {1, 2,3,4,5}, index;
	// int arr[ 5 ];

	printf("\n Enter Elements of array :: ");
	for(index=0; index<SIZE; index++)
	{
		printf("\n arr[%d] ::", index);
		//scanf("%d", &arr[index]); // array notation
		//scanf("%d", &index[arr]); // array notation
		scanf("%d", (arr+index)); // pointer notation
		scanf("%d", (index+arr)); // pointer notation
	}

	printf("\n Elements of array :: \n");
	for(index=0; index<SIZE ; index++)
	{
		//array notation
		//printf("\n arr[%d] %d [%u]", index, arr[index], &arr[index]);
		//printf("\n [%d]arr   %d [%u]", index, index[arr], &index[arr]);
		// pointer notation
		//printf("\n *(arr+%d) %d [%u]", index, *(arr+index), (arr+index));
		printf("\n *(%d+arr) %d [%u]", index, *(index+arr), (index+arr));
	}
	printf("\n size of array in bytes =%d", sizeof(arr));
	printf("\n &arr=%u &arr[0]=%u arr=%u\n", &arr, &arr[0], arr);
	printf("\n &arr+1=%u &arr[0]+1=%u arr+1=%u\n", &arr+1, &arr[0]+1, arr+1);

	printf("\n\n *arr=%d\n", *arr);

/*	arr++;   // lvalue req we can not change base address of array
	++arr;
	--arr;
	arr--; */

	printf("\n ++arr[0]=%d",++arr[0]); //allowed
	printf("\n arr[0]++=%d",arr[0]++); //allowed
	printf("\n --arr[0]=%d",--arr[0]); //allowed
	printf("\n arr[0]--=%d",arr[0]--); //allowed




	return 0;
}

