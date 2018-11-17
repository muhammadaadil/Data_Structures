//Qeque(Double Endeded Deque) implementation using circular array concept
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXDEQUE 10
typedef char DequeEntry;
typedef enum boolean{FALSE,TRUE}Boolean;
typedef struct deque
{
	int count;
	int front;
	int rear;
	DequeEntry entry[MAXDEQUE];
}Deque;

void CreateDeque(Deque*);
void Append_Front(DequeEntry,Deque*);
void Serve_Front(DequeEntry*,Deque*);
void Append_Rear(DequeEntry,Deque*);
void Serve_Rear(DequeEntry*,Deque*);
Boolean DequeEmpty(Deque*);
Boolean DequeFull(Deque*);
void Display(Deque*);
void Error(const char*);

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

/*CreateDeque: create the Deque.
Pre: None.
Post: The Deque dq has been initialized to be empty. */
void CreateDeque(Deque* dq)
{
	dq->count=0;
	dq->front=1;
	dq->rear=0;
}

/*Append_Front: append an entry to the Deque from front.
Pre: The Deque q has been created and is not full.
Post: The entry x has been stored in the Deque as its first entry.
Uses: DequeFull,Error*/
void Append_Front(DequeEntry x,Deque* dq)
{
	//if(DequeFull(dq))
	{
	//	Error("Cannot append an entry to a full Deque.");
	//	return;
	}
	//dq->count+=1;
	printf("count = %d",dq->count);
	getch();
	//if(dq->front==0)
	  //  dq->front=15;
	//else
	//	dq->front--;
	//dq->entry[dq->front]=x;
}

/*Serve_Front: remove the first entry from Deque
Pre: The Deque q has been created and is not empty
Post: The first  entry in the Deque has been removed and returned as the value of x.
Uses: DequeEmpty,Error */
void Serve_Front(DequeEntry* x,Deque* dq)
{
	if(DequeEmpty(dq))
	{
	    Error("Cannot serve from an empty Deque.");	
	    return;
    }
	dq->count--;
	*x=dq->entry[dq->front];
	dq->front=(dq->front+1)%MAXDEQUE;
}

/*Append_Rear: Inserts new entry from rear side.
Pre: The deque exists, has been initialized and is not full.
Post: The entry x has been inserted at the end of queue.
Uses: QueueFull,Error */
void Append_Rear(DequeEntry x,Deque *dq)
{
    if(DequeFull(dq))
	{
	   Error("Can't Append on a full deque!");
	   return;	
	}	
	dq->count++;
	dq->rear=(dq->rear+1)%MAXDEQUE;
	dq->entry[dq->rear]=x;
}

/*Serve_Rear: Removes elemnet from rear side and returns it in var.
Pre: The deque exists, has been initialized and is not empty.
Post: The last entry has been removed and returned in var.
Uses: DequeEmpty,Error*/
void Serve_Rear(DequeEntry* var,Deque* dq)
{
	if(DequeEmpty(dq))
	{
		Error("Can't serve on an empty deque!");
		return;
	}
	dq->count--;
	*var=dq->entry[dq->rear];
	if(dq->rear==0)
	   dq->rear=15;
	else 
	   dq->rear--;
}

/*DequeEmpty: returns non-zero if Deque is empty
Pre: The Deque q has been created
Post: The function returns non-zero if the Deque q is empty, zero otherwise*/
Boolean DequeEmpty(Deque* q)
{
	if(q->count<=0)
	   return TRUE;
	else 
	   return FALSE;
}

/*DequeFull: return non-zero if Deque if full
Pre: The Deque q has been created
Post: The function returns non-zero if the Deque is full, zero otherwise*/
Boolean DequeFull(Deque* q)
{
    if(q->count>=MAXDEQUE)
        return TRUE;
    else
       return FALSE;
}

/*Pre: Points to the message to be printed
Post: the function prints the message and returns after any key hit.*/
void Error(const char* s)
{
	fprintf(stderr,"%s\n",s);
	getch();
}

/*Display: Displays deque elements from front.
Pre: The deque exists and has been initialized.
Post: Deque has been displayed from front.*/
void Display(Deque* dq)
{
	//int count=dq->count;
	//int front=dq->front;
	printf("\ncount= %d",dq->count++);
	//while(count-- >0)
	{
	//	if(front==MAXDEQUE)
	//	    front=0;
	//    printf("|%d| ",dq->entry[front++]);	
	}
}
