/*
 * stack.h
 *
 *  Created on: 15-Sep-2019
 *      Author: sunbeam
 */

#ifndef STACK_H_
#define STACK_H_

#define SIZE 5

typedef struct
{
	int arr[SIZE];
	int top;
}stack_t;

void init_stack(stack_t *ps);
int is_stack_full(stack_t *ps);
int is_stack_empty(stack_t *ps);
void push_element(stack_t *ps, int ele);
void pop_element(stack_t *ps);
int peek_element(stack_t *ps);


#endif /* STACK_H_ */
