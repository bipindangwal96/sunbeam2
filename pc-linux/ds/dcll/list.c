/*
 * list.c
 *
 *  Created on: 15-Sep-2019
 *      Author: sunbeam
 */
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void init_list(list_t *list)
{
	list->head = NULL;
	list->cnt = 0;
}

int is_list_empty(list_t *list)
{
	return ( list->head == NULL );
}

node_t *create_node(int data)
{
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	if( temp == NULL)
	{
		perror("malloc() failed !!!\n");
		exit(1);
	}

	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

void add_node_at_last_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list empty -- attach newly created node to the head
	if( is_list_empty(list))
	{
		list->head = newnode;
		list->head->next = list->head;
		list->head->prev = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//store the addr of first node into the next part of newly created node
		newnode->next = list->head;
		//store the addr of cur last node into the prev part of newly created node
		newnode->prev = list->head->prev;
		//store the addr of newly created node into the next part of cur last node
		list->head->prev->next = newnode;
		//store the addr of newly created node into the prev part of first node
		list->head->prev = newnode;
		list->cnt++;
	}
}

void add_node_at_first_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list empty -- attach newly created node to the head
	if( is_list_empty(list))
	{
		list->head = newnode;
		list->head->next = list->head;
		list->head->prev = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//store the addr of cur first node into next part of newly created node
		newnode->next = list->head;
		//store the addr of last node into the prev of newly created node
		newnode->prev = list->head->prev;
		//store the addr of newly created node into the prev part of cur first node
		list->head->prev = newnode;
		//store the addr of newly created node into the head
		list->head = newnode;
		//update next part of last node with updated value of head
		list->head->prev->next = list->head;
		list->cnt++;
	}
}


void display_list(list_t *list)
{
	//start the traversal from the first node
	node_t *trav = list->head;
	printf("list in forward dir is: ");
	do
	{
		printf("%4d", trav->data);
		trav = trav->next;
	}while( trav != list->head );
	printf("\n");

	//start the traversal from the last node
	trav = list->head->prev;
	printf("list in backward dir is: ");
	do
	{
		printf("%4d", trav->data);
		trav = trav->prev;
	}while( trav != list->head->prev );
	printf("\n");
}

void delete_node_at_first_position(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		//if list contains only one node
		if( list->head == list->head->next )
		{
			//delete the node and make head as NULL & cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			//store the addr of cur first node which to be deleted in a temp
			node_t *temp = list->head;
			//store the addr of cur second node into the head
			list->head = list->head->next;
			//store the addr of last node into the prev part of new first node
			list->head->prev = temp->prev;
			//update next part of last node to the new first node
			temp->prev->next = list->head;

			//delete the node
			free(temp);
			temp = NULL;
			list->cnt--;
		}

	}
	else
		printf("list is empty !!!\n");
}

void delete_node_at_last_position(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		//if list contains only one node
		if( list->head == list->head->next )
		{
			//delete the node and make head as NULL & cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			//store the addr of cur last node which to be deleted in a temp
			node_t *temp = list->head->prev;

			//store the addr of first node into the prev part of cur second last node
			temp->prev->next = list->head;
			//store the addr of cur second last node into the prev part of first node
			list->head->prev = temp->prev;
			//delete the node
			free(temp);
			temp = NULL;

			list->cnt--;
		}

	}
	else
		printf("list is empty !!!\n");
}


void free_list(list_t *list)
{
	if( !is_list_empty(list))
	{
		while( !is_list_empty(list))
			delete_node_at_last_position(list);

			//delete_node_at_first_position(list);
		printf("list freed successfully...\n");
	}
	else
		printf("list is empty !!!\n");
}
