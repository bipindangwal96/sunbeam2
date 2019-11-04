/*
 * list.c
 *
 *  Created on: 09-Sep-2019
 *      Author: sunbeam
 */

/* this file contains definitions of list functionalities */

#include<stdio.h>
#include<stdlib.h>
#include"list.h"


void init_list(list_t *l1)
{
	l1->head = NULL;
	l1->cnt = 0;
}

int is_list_empty(list_t *l1)
{
	return ( l1->head == NULL );
}

node_t *create_node(int data)
{
	//allocate memory dynamically for a node
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	if( temp == NULL )
	{
		perror("malloc() failed !!!\n");
		exit(1);
	}
	//initialize its members
	temp->data =data;
	temp->next = NULL;

	//return the addr of newly created node to the calling function
	return temp;
}

//void add_node_at_last_position(list_t *l1=&l1, int data=10)
void add_node_at_last_position(list_t *l1, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty then attach newly created node to the head
	if( is_list_empty(l1) )
	{
		//store the addr of newly created node into the head
		l1->head = newnode;
		l1->cnt++;
	}
	else//if list is not empty
	{
		//start traversal from first node
		node_t *trav = l1->head;

		//traverse list till last node
		while( trav->next != NULL )
		{
			trav = trav->next;//move trav pointer to the next node
		}

		//attach newly created node to the last node i.e. store the addr of newly created node
		//into the next part of last node
		trav->next = newnode;
		l1->cnt++;
	}
}

void display_list(list_t *l1)
{
	//if list is not empty - then traverse the list and visit data part of each node
	if( !is_list_empty(l1) )
	{
		//start traversal from first node
		node_t *trav = l1->head;
		//printf("no. of nodes in the list are: %d\n", count_nodes(l1));
		printf("no. of nodes in the list are: %d\n", l1->cnt);
		printf("list is: ");

		//traverse the list till last node including
		while( trav != NULL )
		{
			//display data part
			printf("%d ->", trav->data);
			trav = trav->next;//move trav pointer to its next node
		}
		printf("NULL\n");
	}
	else
	{
		printf("list is empty !!!\n");
	}
}

void add_node_at_first_position(list_t *l1, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty then attach newly created node to the head
	if( is_list_empty(l1) )
	{
		//store the addr of newly created node into the head
		l1->head = newnode;
		l1->cnt++;
	}
	else//if list is not empty
	{
		//store the addr of current first node into the next part newly created node
		newnode->next = l1->head;
		//store the addr of newly created node into the head
		l1->head = newnode;
		l1->cnt++;
	}
}

int count_nodes(list_t *l1)
{
	int cnt = 0;

	node_t *trav = l1->head;

	while( trav != NULL )
	{
		cnt++;
		trav = trav->next;
	}

	return cnt;
}

void add_node_at_specific_pos(list_t *l1, int data, int pos)
{
	if( pos == 1 )//add node at first pos
		add_node_at_first_position(l1, data);
	else if( pos == l1->cnt + 1 )//add node at last pos
		add_node_at_last_position(l1, data);
	else//pos is in between pos
	{
		//create a new node
		node_t *newnode = create_node(data);

		//traverse the list till (pos-1)th node
		int i = 1;
		node_t *trav = l1->head;

		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of cur (pos)th node into next part of newly created node
		newnode->next = trav->next;
		//store the addr of newly created node into the next part (pos-1)th node
		trav->next = newnode;
		l1->cnt++;
	}
}

void delete_node_at_first_position(list_t *l1)
{
	//if list is not empty
	if( !is_list_empty(l1))
	{
		//if list contains only one node
		if( l1->head->next == NULL )
		{
			//delete the node, make head as NULL and cnt as 0
			free(l1->head);
			l1->head = NULL;
			l1->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			//store the addr of cur first node into a temp pointer var which is to be deleted
			node_t *temp = l1->head;
			//store the addr of cur second node into the head
			l1->head = l1->head->next;
			//delete the node
			free(temp);
			temp = NULL;
			l1->cnt--;
		}
	}
	else
		printf("list is empty !!!\n");
}

void delete_node_at_last_position(list_t *l1)
{
	//if list is not empty
	if( !is_list_empty(l1))
	{
		//if list contains only one node
		if( l1->head->next == NULL )
		{
			//delete the node, make head as NULL and cnt as 0
			free(l1->head);
			l1->head = NULL;
			l1->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			//start the traversal from the first node
			node_t *trav = l1->head;
			//traverse the list till second last node
			while( trav->next->next != NULL )
				trav = trav->next;

			//delete last node
			free(trav->next);
			//and make next part of cur second last node as NULL
			trav->next = NULL;
			l1->cnt--;
		}
	}
	else
		printf("list is empty !!!\n");
}

void delete_node_at_specific_position(list_t *l1, int pos)
{
	if( pos == 1 )
		delete_node_at_first_position(l1);
	else
	if( pos == l1->cnt )
		delete_node_at_last_position(l1);
	else//if the pos is in between position
	{
		int i = 1;
		node_t *temp = NULL, *trav = l1->head;
		//traverse the list till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of the node to be deleted into a temp pointer var
		temp = trav->next;
		//store the addr of cur (pos)th node into the next part (pos-1)th node
		trav->next = temp->next;
		//delete the node
		free(temp);
		temp = NULL;
		l1->cnt--;
	}
}

void free_list(list_t *l1)
{
	//if list is not empty
	if( !is_list_empty(l1))
	{
		while( !is_list_empty(l1) )
			delete_node_at_last_position(l1);
			//delete_node_at_first_position(l1);

		printf("list freed successfully !!!\n");
	}
	else
		printf("list is empty !!!\n");
}

void display_reverse(list_t *l1, node_t *trav)
{
	if( trav == NULL )
		return;

	display_reverse(l1, trav->next);
	printf("%4d", trav->data);
}

void reverse_list(list_t *l1)
{
	node_t *t1 = l1->head;
	node_t *t2 = t1->next;
	t1->next = NULL;

	while( t2 != NULL )
	{
		node_t *t3 = t2->next;
		t2->next = t1;

		t1 = t2;
		t2 = t3;
	}

	l1->head = t1;
}

















