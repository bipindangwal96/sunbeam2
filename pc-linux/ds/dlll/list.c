/*
 * list.c
 *
 *  Created on: 14-Sep-2019
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
	//alocate memory dynamically
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	if( temp == NULL )
	{
		perror("malloc() failed !!!\n");
		exit(1);
	}
	//initialize its members
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;
	//return the starting addr of newly created node to the calling function
	return temp;

}

void add_node_at_last_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty -- attach newly created node to the head
	if( is_list_empty(list))
	{
		//store the addr of newly created node into the head
		list->head = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//start the traversal from the first node
		node_t *trav = list->head;

		//traverse list till last node
		while( trav->next != NULL )
			trav = trav->next;

		//store the addr of cur last node into prev of newly created node
		newnode->prev = trav;
		//store the addr of newly created node into the next part of last node
		trav->next = newnode;
		list->cnt++;
	}
}

void add_node_at_first_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty -- attach newly created node to the head
	if( is_list_empty(list))
	{
		//store the addr of newly created node into the head
		list->head = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//store the addr of cur first node into next part of newly created node
		newnode->next = list->head;
		//store the addr of newly created node into the prev part of cur first node
		list->head->prev = newnode;
		//store the addr of newly created node into the head
		list->head = newnode;

		list->cnt++;
	}
}

void display_list(list_t *list)
{
	node_t *trav = list->head;
	node_t *temp = NULL;

	printf("list in forward dir is :  ");
	while( trav != NULL )
	{
		temp = trav;
		printf("%4d", trav->data);
		trav = trav->next;
	}
	printf("\n");

	trav = temp;
	printf("list in backward dir is : ");
	while( trav != NULL )
	{
		printf("%4d", trav->data);
		trav = trav->prev;
	}
	printf("\n");
}

void add_node_at_specific_position(list_t *list, int data, int pos)
{
	if( pos == 1 )
		add_node_at_first_position(list, data);
	else
	if( pos == list->cnt + 1 )
		add_node_at_last_position(list, data);
	else
	{
		int i = 1;
		//create a newnode
		node_t *newnode = create_node(data);

		//start the traversal from first node
		node_t *trav = list->head;

		//traverse the list till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of cur (pos-1)th node into prev part of newly created node
		newnode->prev = trav;
		//store the addr of cur (pos)th node into the next part of newly created node
		newnode->next = trav->next;
		//store the addr of newly created node into the prev part of cur (pos)th node
		trav->next->prev = newnode;
		//store the addr of newly created node into the next part of (pos-1)th node
		trav->next = newnode;

		list->cnt++;
	}
}

void delete_node_at_first_position(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		//if list contains only one node
		if( list->head->next == NULL )
		{
			//delete the node and make head as NULL and cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			//store the addr of cur second node into the head
			list->head = list->head->next;
			//delete the first node
			free(list->head->prev);
			//make prev part of new first node as NULL
			list->head->prev = NULL;
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
		if( list->head->next == NULL )
		{
			//delete the node and make head as NULL and cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			//start the traversal from the first node
			node_t *trav = list->head;

			//traverse the list till second last node
			while( trav->next->next != NULL )
				trav = trav->next;

			//delete the last node
			free(trav->next);
			//make next part of second last node as NULL
			trav->next = NULL;

			list->cnt--;
		}
	}
	else
		printf("list is empty !!!\n");
}

/*
void delete_node_at_specific_position(list_t *list, int pos)
{
	if( pos == 1 )
		delete_node_at_first_position(list);
	else
	if( pos == list->cnt )
		delete_node_at_last_position(list);
	else//if pos is in between pos
	{
		int i = 1;
		node_t *trav = list->head;
		node_t *temp = NULL;
		//traverse the list till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of node to be delete in a temp pointer var
		temp = trav->next;
		//store the addr of cur (pos-1)th node into the prev part of cur (pos+1)th node
		temp->next->prev = trav;
		//store the addr of cur (pos+1)th node into the next part of cur (pos-1)th node
		trav->next = temp->next;
		//delete the node
		free(temp);
		temp = NULL;

		list->cnt--;
	}
}
*/

void delete_node_at_specific_position(list_t *list, int pos)
{
	if( pos == 1 )
		delete_node_at_first_position(list);
	else
	if( pos == list->cnt )
		delete_node_at_last_position(list);
	else//if pos is in between pos
	{
		int i = 1;
		node_t *trav = list->head;
		//traverse the list till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		trav->next = trav->next->next;
		free(trav->next->prev);
		trav->next->prev = trav;

		list->cnt--;
	}
}

void free_list(list_t *list)
{
	if( !is_list_empty(list) )
	{
		while( !is_list_empty(list))
			delete_node_at_last_position(list);
			//delete_node_at_first_position(list);
		printf("list freed successfully....\n");
	}
	else
		printf("list is empty !!!\n");
}



















