/*
 * node.h
 *
 *  Created on: 09-Sep-2019
 *      Author: sunbeam
 */

/* this file contains definition of node structure */

#ifndef NODE_H_
#define NODE_H_

typedef struct node
{
	int data;//data part -- 4 bytes
	struct node *next;//pointer part -- self referential pointer variable -- 4 bytes
}node_t;

#endif /* NODE_H_ */
