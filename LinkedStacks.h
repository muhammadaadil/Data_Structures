//linked implementation of stacks
#include"common.h"

#define MAXINT 3000
typedef int StackEntry;
typedef struct node
{
	StackEntry entry;
	struct node* next;
}Node;
typedef struct stack
{
	Node* top;
}Stack;

void CreateStack(Stack*);
Node* MakeNode(StackEntry);
void Push(StackEntry,Stack*);
void Pop(StackEntry*,Stack*);
Boolean StackEmpty(Stack*);
int StackSize(Stack*);
void ClearStack(Stack*);
void StackTop(StackEntry*,Stack*);

/*CreateStack:Initializes stack to be empty
Pre: Stack has been declared.
Post: Stack is initialized to empty*/
void CreateStack(Stack* s)
{
	s->top=NULL;
}

/*MakeNode: Creates dynamically a new node
Pre: None
Post: A new node has been created and value in argument item is stored in it and address is returned*/
Node* MakeNode(StackEntry item)
{
    Node* np=(Node*)malloc(sizeof(Node));
	if(np==NULL)
	    Error("Exhausted memory!");
	np->entry=item;
	np->next=NULL;
	return np;
} 

/*Push: Pushes a new node on stack
Pre: Stack exists and has been initialized
Post: The argument item has been stored at the top of stack*/
void Push(StackEntry item,Stack* s)
{
	Node* np=MakeNode(item);
	if(np==NULL)
	   Error("Attempted to push a non-existing node!");
	np->next=s->top;
	s->top=np;
}

/*StackEmpty: Checks if stack is empty
Pre: Stack exists and has been initialized
Post: Has returned true if stack is empty false otherwise*/
Boolean StackEmpty(Stack* s)
{
	if(s->top==NULL)
	   return TRUE;
	else
	   return FALSE;
}

/*Pop: Removes top entry and returns it
Pre: Stack exists and has been initialized
Post: Top element of stack has been removed and returned in item*/
void Pop(StackEntry* item,Stack* s)
{
	if(StackEmpty(s))
	    Error("Attempted to pop an empty stack!");
	*item=s->top->entry;
	s->top=s->top->next;
}

/*StackSize: Returns the size of stack
Pre: Stack exists and has been initialized
Post: Size of stack has been returned*/
int StackSize(Stack* s)
{
	int size=0;
	Node* temp=s->top;
	while(temp!=NULL)
	{
		temp=temp->next;
		size++;
	}
	return size;
}

/*ClearStack: Clears stack by deleting all nodes
Pre: Stack exists and has been initialized
Post: All nodes had been deleted and stack top is set to NULL*/
void ClearStack(Stack* s)
{
	s->top=NULL;
}

/*StackTop: Sets the argument item to top of stack if stack is not empty else to maxint
Pre: Stack exists and has been initialized
Post: Stack top has been returned in item argument*/
void StackTop(StackEntry* item,Stack* s)
{
	*item=s->top->entry;
}
