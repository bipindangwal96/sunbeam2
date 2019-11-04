/*
 * stack.c
 *
 *  Created on: 17-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>
#include"stack.h"

void init_stack(stack_t *ps)
{
	ps->top = -1;
}

int is_stack_empty(stack_t *ps)
{
	return ( ps->top == -1 );
}

int is_stack_full(stack_t *ps)
{
	return ( ps->top == SIZE-1 );
}

void push_element(stack_t *ps, node_t *ele)
{
	if( !is_stack_full(ps) )
	{
		ps->top++;
		ps->arr[ ps->top ] = ele;
	}
	else
		printf("stack overflow !!!\n");
}

void pop_element(stack_t *ps)
{
	if( !is_stack_empty(ps) )
	{
		ps->top--;
	}
	else
		printf("stack underflow !!!\n");
}

node_t *peek_element(stack_t *ps)
{
	if( !is_stack_empty(ps) )
	{
		return ( ps->arr[ ps->top ] );
	}
	else
	{
		printf("stack underflow !!!\n");
		return NULL;
	}
}

