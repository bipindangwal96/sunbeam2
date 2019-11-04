/*
 * stack.h
 *
 *  Created on: 17-Sep-2019
 *      Author: sunbeam
 */

#ifndef STACK_H_
#define STACK_H_

#include"node.h"

#define SIZE 20

typedef struct
{
	node_t *arr[SIZE];
	int top;
}stack_t;

void init_stack(stack_t *ps);
int is_stack_empty(stack_t *ps);
int is_stack_full(stack_t *ps);
void push_element(stack_t *ps, node_t *ele);
void pop_element(stack_t *ps);
node_t *peek_element(stack_t *ps);



#endif /* STACK_H_ */
