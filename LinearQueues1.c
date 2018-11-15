/*This implementation uses two indexes front and rear.If rear reaches maxqueue elements are shifted
to front if any room*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"common.h"
#define MAXQUEUE 5

typedef int QueueEntry; 
typedef struct queue
{
	int front;
	int rear;
	QueueEntry entry[MAXQUEUE];
}Queue;

void CreateQueue(Queue*);
void Append(QueueEntry,Queue*);
void Serve(QueueEntry*,Queue*);
void Display(Queue*);
Boolean QueueFull(Queue*);
Boolean QueueEmpty(Queue*);
void ShiftToFront(Queue*);

int main()
{
    Queue q;
    QueueEntry value;
    int ch;
    CreateQueue(&q);
	while(1)
    {
    	system("cls");
    	printf("You can do the following....\n");
    	printf("1: Append\n");
    	printf("2: Serve\n");
    	printf("3: Display\n");
    	printf("4: Exit\n\n");
    	printf("         Enter you choice: ");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			printf("\nEnter Value: ");
    			scanf("%d",&value);
    			Append(value,&q);
    			break;
    		case 2:
    			Serve(&value,&q);
    			break;
    		case 3:
    			Display(&q);
    			getch();
    			break;
    		case 4:
    			exit(0);
    		default:
    			printf("\t\t\tInvalid Choice.......!  Try Again...\a");
    			break;
		}
	}
    return 0;  	
}
void CreateQueue(Queue* q)
{
	q->front=0;
	q->rear=-1;
}

void Append(QueueEntry x,Queue* q)
{
	if(QueueFull(q))
	    Error("Can't Append on a full queue!");
	else if(q->rear==(MAXQUEUE-1))
	    ShiftToFront(q);
	q->rear++;
	q->entry[q->rear]=x;
}

void Serve(QueueEntry* var,Queue* q)
{
	if(QueueEmpty(q))
	    Error("Can't Serve on an empty queue!");
	int count=0;
	*var=q->entry[q->front];
	q->front++;
}

Boolean QueueFull(Queue* q)
{
	if(q->front<=0 && q->rear>=(MAXQUEUE-1))
	    return TRUE;
	else
	   return FALSE;
}

Boolean QueueEmpty(Queue* q)
{
	if(q->rear==-1)
	   return TRUE;
	else
	   return FALSE;
}

void Display(Queue* q)
{
    int count;
    for(count=q->front;count<=q->rear;count++)
        printf("|%d| ",q->entry[count]);
}

void ShiftToFront(Queue* q)
{
	int count;
	int offset=(q->rear)-(q->front);
	for(count=q->front;count<=q->rear;count++)
	    q->entry[count-offset]=q->entry[count];
	q->front-=offset;
	q->rear-=offset;
}
