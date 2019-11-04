/*
 * node.h
 *
 *  Created on: 14-Sep-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_


typedef struct node
{
	struct node *prev;//4 bytes
	int data;//4 bytes
	struct node *next;//4 bytes
}node_t;


#endif /* NODE_H_ */
