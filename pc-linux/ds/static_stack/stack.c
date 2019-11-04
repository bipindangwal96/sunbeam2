/*
 * stack.c
 *
 *  Created on: 15-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>
#include"stack.h"

void init_stack(stack_t *ps)
{
	ps->top = -1;
}

int is_stack_full(stack_t *ps)
{
	return ( ps->top == SIZE-1 );
}

int is_stack_empty(stack_t *ps)
{
	return ( ps->top == -1 );
}

void push_element(stack_t *ps, int ele)
{
	/*
	//- increment the value of top by 1
	ps->top++;
	//- push ele into the stack at top pos
	ps->arr[ ps->top ] = ele;
	*/
	ps->arr[ ++ps->top ] = ele;
}

void pop_element(stack_t *ps)
{
	//- decrement the value of top by 1 (i.e. pop ele from the stack at top pos)
	ps->top--;
}

int peek_element(stack_t *ps)
{
	//- get the value of topmost ele (without incrementing/decrementing top)
	return ps->arr[ ps->top ];
}



