/*
 * main.c
 *
 *  Created on: 09-Sep-2019
 *      Author: sunbeam
 */

/* file inclusion section */
#include<stdio.h>


/* global declaration section */

#define SIZE 8
#define SWAP(a,b) { int t = a; a = b; b = t; }

//function declarations
void selection_sort(int *arr);
void bubble_sort(int *arr);
void display_array_elements(int *arr);
void insertion_sort(int *arr);

int iterations = 0;
int comparisons = 0;

//entry point function
int main(void)
{
	//int arr[SIZE] = { 60, 70, 20, 40, 50, 10, 30, 80 };
	int arr[SIZE] = { 10,20,30,40,50,60,70,80 };
	//int arr[SIZE] = { 40,10,30,20,50,60 };
	//int arr[SIZE] = {10,20,30,40,50,60};
	display_array_elements(arr);

	//selection_sort(arr);
	//bubble_sort(arr);
	insertion_sort(arr);
	display_array_elements(arr);


	return 0;
}//end of main() function

/* global declaration section */

//function definitions

void insertion_sort(int *arr)
{
	int i;
	int j;
	int key;
	int w_cnt = 0;

	iterations=0;

	for( i = 1 ; i < SIZE ; i++ )
	{
		iterations++;
		key = arr[i];
		j = i-1;

		while( j >= 0 && arr[j] >= key )
		{
			w_cnt++;
			//shift ele towards right pos
			arr[j+1] = arr[j];
			j--;
		}
		//insert key at its appropriate pos
		arr[j+1] = key;
	}

	printf("no. of iterations are: %d\n", iterations);
	printf("no. of iterations of while loop are : %d\n", w_cnt);
}

void bubble_sort(int *arr)
{
	int it;
	int pos;
	int flag = 1;

	iterations=0;
	for( it = 0 ; it < SIZE-1 && flag == 1 ; it++ )
	{
		flag = 0;
		iterations++;
		for( pos = 0 ; pos < SIZE-it-1 ; pos++ )
		{
			comparisons++;
			//if ele's which are two consecutive positions are not in order
			if( arr[ pos ] > arr[ pos+1 ] )
			{
				flag = 1;
				SWAP(arr[pos], arr[pos+1] );
			}
		}
	}

	printf("no. of comparisons are: %d\n", comparisons);
	printf("no. of iterations are : %d\n", iterations);

}
void selection_sort(int *arr)
{
	int sel_pos;
	int another_pos;

	iterations=0;
	comparisons=0;

	for( sel_pos = 0 ; sel_pos < SIZE-1 ; sel_pos++ )
	{
		iterations++;
		for( another_pos = sel_pos + 1 ; another_pos < SIZE ; another_pos++ )
		{
			comparisons++;
			if( arr[ sel_pos ] > arr[ another_pos ] )
				SWAP(arr[ sel_pos ], arr[ another_pos ]);
		}
	}

	printf("no. of comparisons are: %d\n", comparisons);
	printf("no. of iterations are : %d\n", iterations);
}

void display_array_elements(int *arr)
{
	int index;
	printf("array ele's are: ");
	for( index = 0 ; index < SIZE ; index++ )
	{
		printf("%4d", arr[index]);
	}
	printf("\n");
}

