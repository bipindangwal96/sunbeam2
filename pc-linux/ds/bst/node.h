/*
 * node.h
 *
 *  Created on: 17-Sep-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct node
{
	struct node *left;
	int data;
	struct node *right;
	int visited;
}node_t;




#endif /* NODE_H_ */
