/*
 * queue.h
 *
 *  Created on: 16-Sep-2019
 *      Author: sunbeam
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define SIZE 5

typedef struct
{
	int arr[SIZE];
	int rear;
	int front;
	int cnt;
}queue_t;


void init_queue(queue_t *pq);
int is_queue_full(queue_t *pq);
int is_queue_empty(queue_t *pq);
void enqueu(queue_t *pq, int ele);
void dequeue(queue_t *pq);
int get_front(queue_t *pq);


#endif /* QUEUE_H_ */
