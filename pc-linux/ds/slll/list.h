/*
 * list.h
 *
 *  Created on: 09-Sep-2019
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

void init_list(list_t *l1);
int is_list_empty(list_t *l1);
void add_node_at_last_position(list_t *l1, int data);
void add_node_at_first_position(list_t *l1, int data);
void add_node_at_specific_pos(list_t *l1, int data, int pos);
void delete_node_at_first_position(list_t *l1);
void delete_node_at_last_position(list_t *l1);
void delete_node_at_specific_position(list_t *l1, int pos);
node_t *create_node(int data);
void display_list(list_t *l1);
int count_nodes(list_t *l1);
void free_list(list_t *l1);
void display_reverse(list_t *l1, node_t *trav);
void reverse_list(list_t *l1);

#endif /* LIST_H_ */
