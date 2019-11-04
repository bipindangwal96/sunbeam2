/*
 * queue.c
 *
 *  Created on: 16-Sep-2019
 *      Author: sunbeam
 */

#include"queue.h"

void init_queue(queue_t *pq)
{
	pq->front = pq->rear = -1;
	pq->cnt = 0;
}

int is_queue_full(queue_t *pq)
{
	//return ( pq->front == (pq->rear+1) % SIZE );
	return ( pq->cnt == SIZE );
}

int is_queue_empty(queue_t *pq)
{
	//return ( pq->rear == -1 && pq->front == pq->rear );
	return ( pq->cnt == 0 );
}

void enqueu(queue_t *pq, int ele)
{
	//increment the value of rear by 1
	pq->rear = (pq->rear + 1 ) % SIZE;

	//insert ele into the queue at rear pos
	pq->arr[ pq->rear ] = ele;

	pq->cnt++;
	//- if ( front == -1 ) ==> front = 0
	if( pq->front == -1 )
		pq->front = 0;
}

void dequeue(queue_t *pq)
{
	if( pq->front == pq->rear )//if we are deleting last ele
	{
		pq->front = pq->rear = -1;
		pq->cnt = 0;
	}
	else
	{
		//increment the value of front by 1 , i.e. delete ele from the queue
		pq->front = (pq->front + 1 ) % SIZE;
		pq->cnt--;
	}
}

int get_front(queue_t *pq)
{
	return ( pq->arr[ pq->front ] );
}

/*

//linear queue:

int is_queue_full(queue_t *pq)
{
	return ( pq->rear == SIZE-1 );
}

int is_queue_empty(queue_t *pq)
{
	return ( pq->rear == -1 || pq->front > pq->rear );
}

void enqueu(queue_t *pq, int ele)
{
	//increment the value of rear by 1
	pq->rear++;

	//insert ele into the queue at rear pos
	pq->arr[ pq->rear ] = ele;

	//- if ( front == -1 ) ==> front = 0
	if( pq->front == -1 )
		pq->front = 0;
}

void dequeue(queue_t *pq)
{
	//increment the value of front by 1 , i.e. delete ele from the queue
	pq->front++;

}

*/
