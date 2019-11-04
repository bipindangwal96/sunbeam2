/*
 * main.c
 *
 *  Created on: 07-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>

#define SIZE 8

int comparisons = 0;

void accept_array_elements(int *arr)
{

}

void display_array_elements(int *arr)
{
	int index;
	printf("array ele's are: ");
	for( index = 0 ; index < SIZE; index++ )
	{
		printf("%4d", arr[index]);
	}
	printf("\n");
}

int rec_array_sum(int *arr, int index )
{
	if( index >= SIZE )
		return 0;
	return ( arr[index] + rec_array_sum(arr, index+1));
}

int array_sum(int *arr)
{
	int sum = 0;
	int index;
	for( index = 0 ; index < SIZE ; index++ )
		sum += arr[index];

	return sum;
}

int linear_search(int *arr, int key)
{
	int index;
	comparisons=0;
	for( index = 0 ; index < SIZE ; index++ )
	{
		comparisons++;
		if( key == arr[index] )
			return 1;
	}
	return 0;
}

int binary_search(int *arr, int key )
{
	int left = 0;
	int right = SIZE-1;

	comparisons=0;
	while( left <= right )
	{
		int mid = (left + right)/2;

		comparisons++;
		if( key == arr[mid] )
			return 1;

		if( key < arr[mid] )
			right = mid-1;
		else
			left = mid+1;
	}//end of while loop
	return 0;
}


int main(void)
{
	int arr[SIZE] = {10,20,30,40,50,60,70,80 };
	int key;

	//accept_array_elements(arr);
	display_array_elements(arr);

	printf("sum = %d\n", array_sum(arr));
	printf("sum = %d\n", rec_array_sum(arr, 0));


	printf("enter the key: ");
	scanf("%d", &key);

	//if( linear_search(arr, key) )
	if( binary_search(arr, key))
	{
		printf("no. of comparisons are: %d\n", comparisons);
		printf("key is found in an array\n");
	}
	else
	{
		printf("no. of comparisons are: %d\n", comparisons);
		printf("key is not found in an array\n");
	}

	return 0;
}

