#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"common.h"
#define MAXDEQUE 10

typedef int DequeEntry; 
typedef struct deque
{
	int front;
	int rear;
	DequeEntry entry[MAXDEQUE];
}Deque;

void CreateDeque(Deque*);
void Append_Front(DequeEntry,Deque*);
void Serve_Front(DequeEntry*,Deque*);
void Append_Rear(DequeEntry,Deque*);
void Serve_Rear(DequeEntry*,Deque*);
void Display(Deque*);
Boolean DequeFull(Deque*);
Boolean DequeEmpty(Deque*);

int main()
{
    Deque dq;
    DequeEntry value;
    int ch;
    CreateDeque(&dq);
	while(1)
    {
    	system("cls");
    	printf("You can do the following....\n");
    	printf("1: Append from front\n");
    	printf("2: Append from rear\n");
    	printf("3: Serve from front\n");
    	printf("4: Serve from rear\n");
    	printf("5: Display from front\n");
    	printf("6: Exit\n\n");
    	printf("         Enter you choice: ");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			printf("\nEnter Value: ");
    			scanf("%d",&value);
    			Append_Front(value,&dq);
    			break;
    		case 2:
    			printf("\nEnter Value: ");
    			scanf("%d",&value);
    			Append_Rear(value,&dq);
    			break;
    		case 3:
    			Serve_Front(&value,&dq);
    			break;
    		case 4:
    			Serve_Rear(&value,&dq);
    			break;
    		case 5:
    			Display(&dq);
    			getch();
    			break;
    		case 6:
    			exit(0);
    		default:
    			printf("\t\t\tInvalid Choice.......!  Try Again...\a");
    			break;
		}
	}
    return 0;  	
}
void CreateDeque(Deque* dq)
{
	dq->front=(MAXDEQUE/2);
	dq->rear=(MAXDEQUE/2)-1;
}

void Append_Front(DequeEntry x,Deque* dq)
{
	if(dq->front==0)
	   Error("Can't appened from front!...");
	else
	{
	   dq->front--;
	   dq->entry[dq->front]=x;	
	}
}

void Serve_Front(DequeEntry* var,Deque* dq)
{
	if(DequeEmpty(dq))
	    Error("Can't Serve on an empty Deque!");
	else
	{
    	*var=dq->entry[dq->front];
	    dq->front++;	
	}
	
}

void Append_Rear(DequeEntry x,Deque* dq)
{
	if(dq->rear==MAXDEQUE-1)
	    Error("Can't Append from rear!....");
	else
	{  
	    dq->rear++;
	    dq->entry[dq->rear]=x;	
	}
}

void Serve_Rear(DequeEntry* var,Deque* dq)
{
	if(DequeEmpty(dq))
	   Error("Can't serve on an empty deque!");
	else
	{
	   *var=dq->entry[dq->rear];
	    dq->rear--;	
	}
}

Boolean DequeFull(Deque* dq)
{
	if(dq->front<=0 && dq->rear>=(MAXDEQUE-1))
	    return TRUE;
	else
	   return FALSE;
}

Boolean DequeEmpty(Deque* dq)
{
	if(dq->rear == dq->front-1)
	   return TRUE;
	else
	   return FALSE;
}

void Display(Deque* dq)
{
    int count;
    for(count=dq->front;count<=dq->rear;count++)
        printf("|%d| ",dq->entry[count]);
}
