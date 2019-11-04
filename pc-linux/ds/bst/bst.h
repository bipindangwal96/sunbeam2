/*
 * bst.h
 *
 *  Created on: 17-Sep-2019
 *      Author: sunbeam
 */

#ifndef BST_H_
#define BST_H_

#include"node.h"

typedef struct bst
{
	node_t *root;
}bst_t;

//function declarations
void init_bst(bst_t *t);
int is_bst_empty(bst_t *t);
void add_node(bst_t *t, int data);
node_t *create_node(int data);
void preorder(bst_t *t, node_t *trav);
void inorder(bst_t *t, node_t *trav);
void postorder(bst_t *t, node_t *trav);
void nonrec_preorder(bst_t *t);
void nonrec_inorder(bst_t *t);
void nonrec_postorder(bst_t *t);

#endif /* BST_H_ */
