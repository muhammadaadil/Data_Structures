#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"common.h"
#define MAXQUEUE 6
typedef char QueueEntry;
typedef struct queue
{
	int count;
	int front;
	int rear;
	QueueEntry entry[MAXQUEUE];
}Queue;

Boolean QueueEmpty(Queue*);
Boolean QueueFull(Queue*);
void Append(QueueEntry, Queue*);
void CreateQueue(Queue*);
void Serve(QueueEntry*,Queue*);
int QueueSize(Queue*);
void ClearQueue(Queue*);
void QueueFront(QueueEntry*,Queue*);
void TraverseQueue(Queue*,void(*)(QueueEntry*));

/*CreateQueue: create the queue.
Pre: None.
Post: The queue q has been initialized to be empty. */
void CreateQueue(Queue* q)
{
	q->count=0;
	q->front=0;
	q->rear=-1;
}

/*Append: append an entry to the queue.
Pre: The queue q has been created and is not full.
Post: The entry x has been stored in the queue as its last entry.
Uses: QueueFull,Error*/
void Append(QueueEntry x,Queue* q)
{
	if(QueueFull(q))
	    Error("Cannot append an entry to a full queue.");
	else
	{
		q->count++;
		q->rear=(q->rear+1)%MAXQUEUE;
		q->entry[q->rear]=x;
	}
}

/*Serve: remove the first entry from queue
Pre: The queue q has been created and is not empty
Post: The first  entry in the queue has been removed and returned as the value of x.
Uses: QueueEmpty,Error */
void Serve(QueueEntry* x,Queue* q)
{
	if(QueueEmpty(q))
	    Error("Cannot serve from an empty queue.");
	else
	{
		q->count--;
		*x=q->entry[q->front];
		q->front=(q->front+1)%MAXQUEUE;
	}
}

/*QueueSize: returns the number of entries in queue
Pre: The queue q has been created.
Post: The function returns the number of entries in the queuea q.*/
int QueueSize(Queue* q)
{
	return q->count;
}

/*QueueEmpty: returns non-zero if queue is empty
Pre: The queue q has been created
Post: The function returns non-zero if the queue q is empty, zero otherwise*/
Boolean QueueEmpty(Queue* q)
{
	if(q->count<=0)
	   return TRUE;
	else 
	   return FALSE;
}

/*QueueFull: return non-zero if queue if full
Pre: The queue q has been created
Post: The function returns non-zero if the queue is full, zero otherwise*/
Boolean QueueFull(Queue* q)
{
    if(q->count>=MAXQUEUE)
        return TRUE;
    else
       return FALSE;
}

/*ClearQueue: Clears queue by resetting 
Pre: The queue q exists and has been initialized
Post: The queue q has been cleared*/
void ClearQueue(Queue* q)
{
	q->count=0;
}

/*QueueFront: Returns front of queue in x and queue remains unchanged
Pre: The queue q exists and is initialized
Post: Front of the queue has been returned in x and queue is unchanged*/
void QueueFront(QueueEntry* x,Queue* q)
{
    *x=q->entry[q->front];	
} 

/*TraverseQueue: Visits each element of queue from front and passes its address to a userdefined function.
Pre: The queue q exists and is initialized.
Post: Every element in the queue is modified by userdefined function pointed by function pointer*/
void TraverseQueue(Queue* q,void(*f)(QueueEntry*))
{
	QueueEntry x;
	Queue q1;
	CreateQueue(&q1);
	while(!QueueEmpty(q))
	{
		Serve(&x,q);
		(*f)(&x);
		Append(x,&q1);
	}
	while(!QueueEmpty(&q1))
	{
		Serve(&x,&q1);
		Append(x,q);
	}
}

void TraverseQueue1(Queue* q,void(*f)(QueueEntry*))
{
    int front=q->front;	
    int count=q->count;
    while(count>0)
    {
    	(*f)(&q->entry[front]);
    	front=(front+1)%MAXQUEUE;
    	count--;
	}
}
