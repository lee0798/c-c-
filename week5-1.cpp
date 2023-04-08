//General List operation
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST 100
typedef int Data;
typedef struct {
	Data items[MAX_LIST];
	int len;
} ArrayList;
// Make a list empty.
void InitList(ArrayList* plist);
// Check whether the list is empty.
bool IsEmpty(ArrayList* plist);
// Check whether the list is full.
bool IsFull(ArrayList* plist);
// Insert an item at the k-th position.
void InsertMiddle(ArrayList* plist, int pos, Data item);
// Remove an item at the k-th position.
void RemoveMiddle(ArrayList* plist, int pos);
// Read an item at the k-th position.
Data ReadItem(ArrayList* plist, int pos);
// Print each item in a list in sequence.
void PrintList(ArrayList* plist);
// Make a list empty.
void InitList(ArrayList* plist)
{
	plist->len = 0;
}
// Check whether the list is empty.
bool IsEmpty(ArrayList* plist)
{
	return plist->len == 0;
}
// Check whether the list is full.
bool IsFull(ArrayList* plist)
{
	return plist->len == MAX_LIST;
}
// Insert an item at the k-th position.
void InsertMiddle(ArrayList* plist, int pos, Data item)
{
	if (IsFull(plist) || pos < 0 || pos > plist->len)
		exit(1);
	for (int i = plist->len - 1; i >= pos; i--)
		plist->items[i + 1] = plist->items[i];
	plist->items[pos] = item;
	plist->len++;
}
// Remove an item at the k-th position.
void RemoveMiddle(ArrayList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);
	for (int i = pos; i < plist->len; i++)
		plist->items[i] = plist->items[i + 1];
	plist->len--;
}
// Read an item at the k-th position.
Data ReadItem(ArrayList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);
	return plist->items[pos];
}
// Print each item in a list in sequence.
void PrintList(ArrayList* plist)
{
	for (int i = 0; i < plist->len; i++)
		printf("%d\n", plist->items[i]);
}
int main ()
{
	ArrayList li;
	InitList(&li);
	InsertMiddle(&li, 0, 1);
	InsertMiddle(&li, 1, 2);
	PrintList(&li);

	return 0;
}*/
//Linked List operation
#include <stdio.h>
#include<stdlib.h>
typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;
typedef struct
{
	Node* head;
	int len;
} LinkedList;
// Make a list empty.
void InitList(LinkedList* plist);
// Check whether the list is empty.
bool IsEmpty(LinkedList* plist);
// Insert an item at the k-th position.
void InsertMiddle(LinkedList* plist, int pos, Data item);
// Remove an item at the k-th position.
void RemoveMiddle(LinkedList* plist, int pos);
// Read an item at the k-th position.
Data ReadItem(LinkedList* plist, int pos);
// Print each item in a list in sequence.
void PrintList(LinkedList* plist);
// Remove all nodes in a list in sequence.
void ClearList(LinkedList* plist);
// Make a list empty.
// Make a list empty.
void InitList(LinkedList* plist)
{
	// Create a dummy node;
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->len = 0;
}
// Check whether the list is empty.
bool IsEmpty(LinkedList* plist)
{
	return plist->len == 0;
}
// Insert an item at the k-th position.
void InsertFirst(LinkedList* plist, Data item)
{
	Node* cur, * newNode;
	// Create a new node.
	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = NULL;
	// Link the head pointer to the new node.
	if (plist->head == NULL)
		plist->head = newNode;
	else {
		newNode->next = plist->head;
		plist->head = newNode;
	}
	plist->len++;
}
// Insert an item at the k-th position.
void InsertMiddle(LinkedList* plist, int pos, Data item)
{
	Node* cur, * newNode;
	if (pos < 0 || pos > plist->len)
		exit(1);
	// Create a new node.
	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = NULL;
	// Move the cur pointer to the (k-1)-th position.
	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;
	// Insert the new node to the k-th position.
	newNode->next = cur->next;
	cur->next = newNode;
	plist->len++;
}
	// Remove an item at the k-th position.
	void RemoveMiddle(LinkedList * plist, int pos)
	{
		Node* cur, * temp;
		if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
			exit(1);
		// Move the cur pointer to the (k-1)-th position.
		cur = plist->head;
		for (int i = 0; i < pos; i++)
			cur = cur->next;
		// Remove the node to the k-th position.
		temp = cur->next;
		cur->next = cur->next->next;
		plist->len--;
		free(temp);
	}
	// Read an item at the k-th position.
	Data ReadItem(LinkedList* plist, int pos)
	{
		Node* cur;
		if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
			exit(1);
		// Move the cur pointer to the k-th position.
		cur = plist->head->next;
		for (int i = 0; i < pos; i++)
			cur = cur->next;
		return cur->item;
	}
	// Print each item in a list in sequence.
	void PrintList(LinkedList* plist)
	{
		for (Node* cur = plist->head->next; cur != NULL; cur = cur->next)
			printf("%d\n", cur->item);
	}
	// Remove all nodes in a list in sequence.
	void ClearList(LinkedList* plist)
	{
		while (plist->head->next != NULL)
			RemoveMiddle(plist,0);
		free(plist->head);
	}







