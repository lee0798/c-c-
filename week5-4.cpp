//Dynamic Stack
#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;
typedef struct
{
	Node* top;
} DStack;
// Make stack empty.
void InitStack(DStack* pstack);
// check whether stack is empty.
bool IsEmpty(DStack* pstack);
// Read the item at the top.
Data Peek(DStack* pstack);
// Insert an item at the top.
void Push(DStack* pstack, Data item);
// Remove the item at the top.
void Pop(DStack* pstack);
// Make stack empty.
void InitStack(DStack* pstack)
{
	pstack->top = NULL;
}
// check whether stack is empty.
bool IsEmpty(DStack* pstack)
{
	return pstack->top == NULL;
}
// Read the item at the top.
Data Peek(DStack* pstack)
{
	if (IsEmpty(pstack))
		exit(1);
	return pstack->top->item;
}
void Push(DStack * pstack, Data item)
{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		newNode->next = pstack->top;
		pstack->top = newNode;
}
// Remove the item at the top.
void Pop(DStack* pstack)
{
	Node* temp;
	if (IsEmpty(pstack)) exit(1);
	temp = pstack->top;
	pstack->top = pstack->top->next;
	free(temp);
}
//Dynamic Queue
typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;
typedef struct
{
	Node* front;
	Node* rear;
} DQueue;
// Make a queue empty.
void InitQueue(DQueue* pqueue);
// Check whether a queue is empty.
bool IsEmpty(DQueue* pqueue);
// Read the item at the front.
Data Peek(DQueue* pqueue);
// Insert an item at the rear.
void EnQueue(DQueue* pqueue, Data item);
// Delete an item at the front.
void DeQueue(DQueue* pqueue);
// Make a queue empty.
void InitQueue(DQueue* pqueue)
{
	pqueue->front = pqueue->rear = NULL;
}
// Check whether a queue is empty.
bool IsEmpty(DQueue* pqueue)
{
	return pqueue->front == NULL;
}
// Read the item at the front.
Data Peek(DQueue* pqueue)
{
	if (IsEmpty(pqueue)) exit(1);
	return pqueue->front->item;
}
void EnQueue(DQueue* pqueue, Data item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	if (IsEmpty(pqueue))
		pqueue->front = pqueue->rear = newNode;
	else {
		pqueue->rear->next = newNode;
		pqueue->rear = newNode;
	}
}
void DeQueue(DQueue* pqueue)
{
	Node* temp;
	if (IsEmpty(pqueue)) exit(1);
	temp = pqueue->front;
	if (temp->next == NULL)
		pqueue->front = pqueue->rear = NULL;
	else
		pqueue->front = temp->next;
	free(temp);
}



