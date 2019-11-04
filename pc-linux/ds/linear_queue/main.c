/*
 * main.c
 *
 *  Created on: 16-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int menu(void)
{
	int choice;
	//printf("LINEAR QUEUE\n");
	printf("CIRCULAR QUEUE\n");
	printf("0. EXIT\n");
	printf("1. ENQUEUE\n");
	printf("2. DEQUEUE\n");
	printf("ENTER THE CHOICE: ");
	scanf("%d", &choice);
	return choice;
}

int main(void)
{
	queue_t q;
	int ele;

	init_queue(&q);

	while(1)
	{
		int choice = menu();
		switch( choice )
		{
		case EXIT:
				exit(0);
		case ENQUEUE:
			//- check queue is not full
			if( !is_queue_full(&q))
			{
				printf("enter an ele: ");
				scanf("%d", &ele);
				enqueu(&q, ele);
				printf("%d is inserted into the queue...\n", ele);
			}
			else
				printf("QUEUE OVERFLOW !!!\n");
			break;

		case DEQUEUE:
			//- check queue is not empty
			if( !is_queue_empty(&q) )
			{
				ele = get_front(&q);
				dequeue(&q);
				printf("%d is deleted from the queue\n", ele);
			}
			else
				printf("QUEUE UNDERFLOW !!!\n");
			break;
		}
	}

	return 0;
}
