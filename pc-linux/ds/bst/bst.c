/*
 * bst.c
 *
 *  Created on: 17-Sep-2019
 *      Author: sunbeam
 */

#include<stdio.h>
#include<stdlib.h>
#include"bst.h"
#include"stack.h"

//function definitions
void init_bst(bst_t *t)
{
	t->root = NULL;
}

int is_bst_empty(bst_t *t)
{
	return ( t->root == NULL );
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
	temp->left = NULL;
	temp->right = NULL;

	//initially all the nodes are not visited
	temp->visited = 0;
	//return the starting addr of newly created node
	return temp;

}

void add_node(bst_t *t, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if the bst is empty -- attach newly created node to the root
	if( is_bst_empty(t) )
	{
		//store the addr of newly created node into the root pointer
		t->root = newnode;
	}
	else//if bst is not empty
	{
		//find an appropriate pos to add newly created node
		//start bst traversal from the root node
		node_t *trav = t->root;

		while(1)
		{
			if( data < trav->data )
			{
				//newly created node will be the part of its left subtree
				//if the cur node do not having left subtree
				if( trav->left == NULL )
				{
					 //attach newly created node as a left child
					trav->left = newnode;
					break;
				}
				else//if cur node is having left subtree goto its left subtree
				{
					trav = trav->left;
				}
			}
			else//if( data >= trav->data )
			{
				//newly created node will be the part of its right subtree
				//if the cur node is do not having right subtree
				if( trav->right == NULL )
				{
					//attach newly created node as a right child
					trav->right = newnode;
					break;
				}
				else////if cur node is having right subtree goto its right subtree
				{
					trav = trav->right;
				}
			}
		}//end of while loop
	}
}

void nonrec_preorder(bst_t *t)
{
	if( !is_bst_empty(t) )
	{
		node_t *trav = t->root;
		stack_t s;
		init_stack(&s);

		printf("PREORDER  : ");
		while( trav != NULL || !is_stack_empty(&s) )
		{
			while( trav != NULL )
			{
				//visit the node
				printf("%4d", trav->data);
				//if the cur node is having right child push it into the stack
				if( trav->right != NULL )
					push_element(&s, trav->right);
				//goto its left subtree
				trav = trav->left;
			}

			//if stack is not empty
			if( !is_stack_empty(&s) )
			{
				//pop ele from the stack and store it into trav pointer
				trav = peek_element(&s); pop_element(&s);
			}
		}//end of while loop
		printf("\n");
	}
	else
		printf("bst is empty !!!\n");
}

void nonrec_inorder(bst_t *t)
{
	if( !is_bst_empty(t) )
	{
		node_t *trav = t->root;
		stack_t s;
		init_stack(&s);

		printf("INORDER   : ");
		while( trav != NULL || !is_stack_empty(&s) )
		{
			while( trav != NULL )
			{
				//push cur node into the stack
				push_element(&s, trav);
				//goto its left subtree
				trav = trav->left;
			}

			//if stack is not empty
			if( !is_stack_empty(&s) )
			{
				//pop ele from the stack and store it into trav pointer and visit
				trav = peek_element(&s); pop_element(&s);
				//visit the node
				printf("%4d", trav->data);
				//goto its right subtree
				trav = trav->right;
			}
		}//end of while loop
		printf("\n");
	}
	else
		printf("bst is empty !!!\n");
}

void nonrec_postorder(bst_t *t)
{
	if( !is_bst_empty(t) )
	{
		node_t *trav = t->root;
		stack_t s;
		init_stack(&s);

		printf("POSTORDER  : ");
		while( trav != NULL || !is_stack_empty(&s) )
		{
			while( trav != NULL )
			{
				//push cur node into the stack
				push_element(&s, trav);
				//goto its left subtree
				trav = trav->left;
			}

			//if stack is not empty
			if( !is_stack_empty(&s) )
			{
				//pop ele from the stack and store it into trav pointer and visit
				trav = peek_element(&s); pop_element(&s);
				//if the cur node is having right subtree and it's right child is not visited
				if( trav->right != NULL && trav->right->visited == 0 )
				{
					//push cur node into the stack
					push_element(&s, trav);
					//goto its right subtree
					trav = trav->right;
				}
				else
				{
					//visit the node
					printf("%4d", trav->data);
					//mark the node as visited
					trav->visited = 1;
					//make trav as NULL
					trav = NULL;
				}
			}
		}//end of while loop
		printf("\n");
	}
	else
		printf("bst is empty !!!\n");
}


void preorder(bst_t *t, node_t *trav)
{
	if( trav == NULL )
		return;
	//VLR
	printf("%4d", trav->data);
	preorder(t, trav->left);
	preorder(t, trav->right);
}

void inorder(bst_t *t, node_t *trav)
{
	if( trav == NULL )
		return;
	//LVR
	inorder(t, trav->left);
	printf("%4d", trav->data);
	inorder(t, trav->right);
}

void postorder(bst_t *t, node_t *trav)
{
	if( trav == NULL )
		return;
	//LRV
	postorder(t, trav->left);
	postorder(t, trav->right);
	printf("%4d", trav->data);
}

