/*
 * main.c
 *
 *  Created on: 15-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

enum menu_options{ EXIT, PUSH, POP, PEEK };

int menu(void)
{
	int choice;

	printf("STATIC STACK\n");
	printf("0. EXIT\n");
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. PEEK\n");
	printf("ENTER THE CHOICE: ");
	scanf("%d", &choice);

	return choice;
}

int main(void)
{
	stack_t s;
	int ele;

	init_stack(&s);

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);

		case PUSH:
			//- check stack is not full
			if( !is_stack_full(&s) )
			{
				printf("enter ele: ");
				scanf("%d", &ele);
				push_element(&s, ele);
				printf("%d is pushed into stack ...\n", ele);
			}
			else
				printf("STACK OVERFLOW !!!\n");
			break;

		case POP:
			//- check stack is not empty
			if( !is_stack_empty(&s) )
			{
				ele = peek_element(&s);
				pop_element(&s);
				printf("%d is popped from the stack\n", ele);
			}
			else
				printf("STACK UNDERFLOW !!!\n");
			break;

		case PEEK:
			//- check stack is not empty
			if( !is_stack_empty(&s) )
			{
				printf("topmost ele is: %d\n", peek_element(&s));
			}
			else
				printf("STACK UNDERFLOW !!!\n");

			break;
		}
	}
	return 0;
}

