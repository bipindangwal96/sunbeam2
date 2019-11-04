/*
 * node.h
 *
 *  Created on: 15-Sep-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node_t;



#endif /* NODE_H_ */
