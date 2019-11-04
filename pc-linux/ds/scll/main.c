/*
 * main.c
 *
 *  Created on: 14-Sep-2019
 *      Author: sunbeam
 */

//file inclusion section
#include<stdio.h>
#include<stdlib.h>


//global declaration section
//declarations
typedef struct node
{
	int data;
	struct node *next;
}node_t;

typedef struct list
{
	node_t *head;
	int cnt;
}list_t;


void init_list(list_t *list);
int is_list_empty(list_t *list);
void add_node_at_last_position(list_t *list, int data);
void add_node_at_first_position(list_t *list, int data);
node_t *create_node(int data);
void display_list(list_t *list);
void delete_node_at_first_position(list_t *list);
void delete_node_at_last_position(list_t *list);
void free_list(list_t *list);

int main(void)
{
	list_t l1;

	init_list(&l1);

	add_node_at_last_position(&l1, 10);
	add_node_at_last_position(&l1, 20);
	add_node_at_last_position(&l1, 30);
	add_node_at_last_position(&l1, 40);
	add_node_at_last_position(&l1, 50);

	/*
	add_node_at_first_position(&l1,11);
	add_node_at_first_position(&l1,22);
	add_node_at_first_position(&l1,33);
	add_node_at_first_position(&l1,44);
	add_node_at_first_position(&l1,55);
	add_node_at_first_position(&l1,66);
	*/

	display_list(&l1);

	//delete_node_at_first_position(&l1);
	delete_node_at_last_position(&l1);

	//add_node_at_first_position(&l1, 5);
	display_list(&l1);

	free_list(&l1);


	return 0;
}


//definitions
void init_list(list_t *list)
{
	list->head = NULL;
	list->cnt = 0;
}

int is_list_empty(list_t *list)
{
	return ( list->head == NULL );
}

void display_list(list_t *list)
{
	if( !is_list_empty(list) )
	{
		node_t *trav = list->head;
		printf("no. of nodes in the list are: %d\n", list->cnt);
		printf("list is: ");
		do
		{
			printf("%4d", trav->data);
			trav = trav->next;
		}while( trav != list->head );
		printf("\n");
	}
	else
		printf("list is empty !!!\n");
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
	temp->data = data;
	temp->next = NULL;
	//return the starting addr of newly created node to the calling function
	return temp;
}

void free_list(list_t *list)
{
	if( !is_list_empty(list))
	{
		while( !is_list_empty(list))
			delete_node_at_last_position(list);
			//delete_node_at_first_position(list);
		printf("list freed successfully....\n");
	}
	else
		printf("list is empty !!!\n");
}

void delete_node_at_first_position(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		//if list contains only node
		if( list->head == list->head->next )
		{
			//delete the node and make head as NULL & cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			node_t *trav = list->head;
			//traverse the list till last node
			while( trav->next != list->head )
				trav = trav->next;

			//store the addr of cur second node into the head
			list->head = list->head->next;

			//delete the prev first node
			free(trav->next);
			//update the next part of last node
			trav->next = list->head;
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
		//if list contains only node
		if( list->head == list->head->next )
		{
			//delete the node and make head as NULL & cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt = 0;
		}
		else//if list contains more than one nodes
		{
			node_t *trav = list->head;
			//traverse the list till second last node
			while( trav->next->next != list->head )
				trav = trav->next;

			//delete the last node
			free(trav->next);
			//store the addr of first node into the next part second last node
			trav->next = list->head;
			list->cnt--;
		}
	}
	else
		printf("list is empty !!!\n");
}

void add_node_at_last_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty - attach newly created node to the head
	if( is_list_empty(list))
	{
		list->head = newnode;
		newnode->next = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//start traversal from first node
		node_t *trav = list->head;

		//traverse the list till last node
		while( trav->next != list->head )
			trav = trav->next;

		//attach newly created node to the last node
		trav->next = newnode;
		//store the addr of first node into the next part of modifieid last node
		newnode->next = list->head;
		list->cnt++;
	}
}

void add_node_at_first_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty - attach newly created node to the head
	if( is_list_empty(list))
	{
		list->head = newnode;
		newnode->next = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//start traversal from first node
		node_t *trav = list->head;

		//traverse the list till last node
		while( trav->next != list->head )
			trav = trav->next;

		//store the addr of cur first node into the next part of newly created node
		newnode->next = list->head;
		//store the addr of newly created node into the head
		list->head = newnode;
		//update the next part of last node to newly added node at first pos
		trav->next = list->head;
		list->cnt++;
	}
}
















