//Circular Linked list
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
	Node* tail;
	int len;
} CircularList;
void InsertInitItem(CircularList* plist, Data item)
{
	// Create a new node.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = newNode;
	plist->tail = newNode;
	plist->len++;
}
void InsertFirst(CircularList* plist, Data item)
{
	if (plist->len == 0)
		InsertInitItem(plist, item);
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		newNode->next = plist->tail->next;
		// Connect the back node to the new node.
		plist->tail->next = newNode;
		plist->len++;
	}
}
void InsertLast(CircularList* plist, Data item) {
	if (plist->len == 0)
		InsertInitItem(plist, item);
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		newNode->next = plist->tail->next;
		// Connect the back node to the new node.
		plist->tail->next = newNode;
		plist->tail = newNode;
		plist->len++;
	}
}
void InsertMiddle(CircularList* plist, int pos, Data item) {
	if (plist->len == 0)
		InsertInitItem(plist, item);
	else {
		Node* cur, * newNode;
		cur = plist->tail;
		for (int i = 0; i < pos; i++) // moving (k-1)-th position
			cur = cur->next;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		newNode->next = cur->next;
		cur->next = newNode; // linking the current node to the new node
		plist->len++;
	}
}
void RemoveInitItem(CircularList* plist)
{
	if (IsEmpty(plist)) exit(1);
	if (plist->len == 1) {
		free(plist->tail);
		plist->len--;
		plist->tail = NULL;
	}
}
void RemoveFirst(CircularList* plist)
{
	if (plist->len == 1)
		RemoveInitItem(plist);
	else {
		Node* temp = plist->tail->next;
		plist->tail->next = temp->next;
		free(temp);
		plist->len--;
	}
}
void RemoveLast(CircularList* plist) {
	if (plist->len == 1)
		RemoveInitItem(plist);
	else {
		Node* cur, * temp;
		cur = plist->tail;
		for (int i = 0; i < plist->len - 1; i++)
			cur = cur->next;
		temp = cur->next;
		cur->next = temp->next;
		free(temp);
		plist->tail = cur;
		plist->len--;
	}
}
void RemoveMiddle(CircularList* plist, int pos) {
	if (plist->len == 1)
		RemoveInitItem(plist);
	else {
		Node* cur, * temp;
		cur = plist->tail;
		for (int i = 0; i < pos; i++)
			cur = cur->next;
		temp = cur->next;
		cur->next = temp->next;
		free(temp);
		plist->len--;
	}
}



int main()
{
	return 0;
}*/
//Double Linked List
#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* prev;
	struct _Node* next;
} Node;
typedef struct
{
	Node* head;
	int len;
} DoubleLinkedList;
void InitList(DoubleLinkedList* plist)
{
	Node* dummy1, * dummy2;
	dummy1 = (Node*)malloc(sizeof(Node));
	dummy2 = (Node*)malloc(sizeof(Node));
	dummy1->prev = NULL;
	dummy1->next = dummy2;
	dummy2->prev = dummy1;
	dummy2->next = NULL;
	plist->head = dummy1;
	plist->len = 0;
}
void InsertMiddle(DoubleLinkedList* plist, int pos, Data item)
{
	Node* cur, * newNode;
	// Create a new node.
	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->prev = NULL;
	newNode->next = NULL;
	// Move the cur pointer to the (k-1)-th position.
	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;
	// Insert the new node to the k-th position.
	newNode->prev = cur;
	newNode->next = cur->next;
	cur->next->prev = newNode;
	cur->next = newNode;
	plist->len++;
}
void RemoveMiddle(DoubleLinkedList* plist, int pos) {
	Node* cur, * temp;
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);
	// Move the cur pointer to the (k-1)-th position.
	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;
	// Connect adjacent nodes to remove the k-th node.
	temp = cur->next;
	temp->next->prev = cur;
	cur->next = temp->next;
	// Remove the node to the k-th position.
	plist->len--;
	free(temp);
}


