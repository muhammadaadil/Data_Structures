//Contigous application of stacks
#include"common.h"

#define MAXSTACK 200
#define MAXINT 3000;
typedef int StackEntry;
typedef struct stack
{
	int top;
    StackEntry entry[MAXSTACK];
}Stack;

void Push(StackEntry,Stack*);
void Pop(StackEntry*,Stack*);
Boolean StackEmpty(Stack*);
void CreateStack(Stack*);
Boolean StackFull(Stack*);
void TraverseStack(Stack*,void(*)(StackEntry*));
void ClearStack(Stack*);
void StackTop(StackEntry*,Stack*);

/*CreateStack: Initializes stack to be empty
Pre: Stack exists
Post: Stack is initialized to empty.*/
void CreateStack(Stack* s)
{
	s->top=0;
}

/*StackEmpty: Returns true if stack is empty false otherwise
Pre: Stack exists and has been initialized
Post: Return True if stack is empty false otherwise*/
Boolean StackEmpty(Stack* s)
{
	if(s->top<=0)
	    return TRUE;
	else
	   return FALSE;
}

/*StackFull: Return true if stack is full
Pre: Stack exists and is initialized
Post: Return true if stack is full false otherwise*/
Boolean StackFull(Stack* s)
{
	if(s->top>=MAXSTACK)
	    return TRUE;
	else
	    return FALSE;
}

/*Push: Inserts new elements at the top of stack
Pre: Stack exists and if not full
Post: The argument item has been stored at the top of stack*/
void Push(StackEntry item,Stack* s)
{
	if(StackFull(s))
	   Error("Stack is full");
	else
	   s->entry[s->top++]= item;
}

/*Pop: Deletes the top element of stack
Pre: Stack exists and is not empty
Post: Top of stack is removed and returned in argument time*/
void Pop(StackEntry* item,Stack* s)
{
    if(StackEmpty(s))
	   Error("Stack is empty");
	else
	   *item=s->entry[--s->top];	
}

/*StackSize: Returns number of elements in stack
Pre: Stack exists and is initialized
Post: Function has returned number of elemnts to calling function*/
int StackSize(Stack* s)
{
    return s->top;	
}

/*ClearStack: Clears stack by setting it to empty
Pre: Stack exists 
Post: Stack has been cleared*/
void ClearStack(Stack* s)
{
	s->top=0;
}

/*StackTop: Sets the argument item to top of stack if stack is not empty else to maxint
Pre: Stack exists and has been initialized
Post: Stack top has been returned in item argument*/
void StackTop(StackEntry* item,Stack* s)
{
	if(s->top-1 != 0)
	    *item=s->entry[s->top-1];
	else
	    *item=MAXINT;
}

/*TraverseStack: Acesses and passes each stack entry to a userdefined funtion for modification
Pre: Stack exists and has been initialized
Post: Every stack element is changed as defined by user*/
void TraverseStack(Stack* s,void(*func_ptr)(StackEntry*))
{
	int item;
	if(!StackEmpty(s))
	{
		Pop(&item,s);
		func_ptr(&item);
		TraverseStack(s,func_ptr);
		Push(item,s);
    }
}
