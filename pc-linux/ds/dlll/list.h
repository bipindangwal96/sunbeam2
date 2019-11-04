/*
 * list.h
 *
 *  Created on: 14-Sep-2019
 *      Author: sunbeam
 */

#ifndef LIST_H_
#define LIST_H_

#include"node.h"


typedef struct list
{
	node_t *head;
	int cnt;
}list_t;


void init_list(list_t *list);
int is_list_empty(list_t *list);
void add_node_at_last_position(list_t *list, int data);
void add_node_at_first_position(list_t *list, int data);
void add_node_at_specific_position(list_t *list, int data, int pos);
void display_list(list_t *list);
void delete_node_at_first_position(list_t *list);
void delete_node_at_specific_position(list_t *list, int pos);
void free_list(list_t *list);

#endif /* LIST_H_ */
