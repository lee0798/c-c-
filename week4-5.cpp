//Dequeue operation
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_dequeue 100


typedef int data;
typedef struct {
	int front, rear;
	data items[max_dequeue];

}dequeue;
void initdequeue(dequeue* pdequeue);
bool isfull(dequeue* pdequeue);
bool isempty(dequeue* pdequeue);
void addfront(dequeue* pdequeue, data item);
void addrear(dequeue* pdequeue, data item);
void removefront(dequeue* pdequeue);
void removerear(dequeue* pdequeue);
int peekfront(dequeue* pdequeue);
int peekrear(dequeue* pdequeue);
int indexoffront(dequeue* pdequeue);
int indexofrear(dequeue* pdequeue);



int main() {
	dequeue Deq;
	int num1,num2;
	scanf_s("%d %d", &num1,&num2);
	initdequeue(&Deq);
	addfront(&Deq, num1);
	addrear(&Deq, num2);
	printf("%d\n", isfull(&Deq));
	printf("%d\n", isempty(&Deq));
	printf("%d\n", peekfront(&Deq));
	printf("%d\n", peekrear(&Deq));
	printf("%d\n", indexoffront(&Deq));
	printf("%d\n", indexofrear(&Deq));
	
	return 0;
}

int indexoffront(dequeue* pdequeue)
{
	int a = pdequeue->front;
	return a;
}
int indexofrear(dequeue* pdequeue)
{
	int b = pdequeue->rear;
	return b;
}

void initdequeue(dequeue* pdequeue) {
	pdequeue->front = pdequeue->rear = 0;
}
bool isfull(dequeue* pdequeue) {
	return pdequeue->front == (pdequeue->rear + 1) % max_dequeue;
}
bool isempty(dequeue* pdequeue) {
	return pdequeue->front == pdequeue->rear;
}
void addfront(dequeue* pdequeue, data item) {
	if (isfull(pdequeue)) {
		exit(1);
	}else if(pdequeue->front==0)
	{
		pdequeue->items[pdequeue->front] = item;
		pdequeue->rear = pdequeue->rear + 1;
	}
	else
	{
		pdequeue->front = (pdequeue->front - 1 + max_dequeue) % max_dequeue;
		pdequeue->items[pdequeue->front] = item;
	}
}
void addrear(dequeue* pdequeue, data item) {
	if (isfull(pdequeue)) {
		exit(1);
	}
	pdequeue->items[pdequeue->rear] = item;
	pdequeue->rear = (pdequeue->rear + 1) % max_dequeue;
}
void removefront(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	pdequeue->front = (pdequeue->front + 1) % max_dequeue;
}
void removerear(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	pdequeue->rear = (pdequeue->rear - 1 + max_dequeue) % max_dequeue;
}
int peekfront(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	return pdequeue->items[pdequeue->front];
}
int peekrear(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	return pdequeue->items[pdequeue->rear - 1];
}*/

//using dequeue checking  palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_dequeue 100


typedef int data;
typedef struct {
	int front, rear;
	data items[max_dequeue];

}dequeue;
void initdequeue(dequeue* pdequeue);
bool isfull(dequeue* pdequeue);
bool isempty(dequeue* pdequeue);
void addfront(dequeue* pdequeue, data item);
void addrear(dequeue* pdequeue, data item);
void removefront(dequeue* pdequeue);
void removerear(dequeue* pdequeue);
int peekfront(dequeue* pdequeue);
int peekrear(dequeue* pdequeue);
int indexoffront(dequeue* pdequeue);
int indexofrear(dequeue* pdequeue);
bool checkPalindrome(char* str, int len);



int main() {
	int Len;
	scanf_s("%d", &Len);
	char* voca = (char*)malloc(sizeof(char) * (Len+1));
	scanf_s("%s", voca);
	printf("%d", checkPalindrome(voca, Len));
	free(voca);


	return 0;
}



bool checkPalindrome(char* str, int len)
{
	dequeue deq;
	initdequeue(&deq);
	for (int i = 0; i < len; i++)
		addrear(&deq, str[i]);
	while (len > 1)
	{
		if (peekfront(&deq) == peekrear(&deq))
		{
			removefront(&deq), removerear(&deq);
			len = len - 2;
		}
		else
			return false;
	}
	return true;
}
int indexoffront(dequeue* pdequeue)
{
	int a = pdequeue->front;
	return a;
}
int indexofrear(dequeue* pdequeue)
{
	int b = pdequeue->rear;
	return b;
}

void initdequeue(dequeue* pdequeue) {
	pdequeue->front = pdequeue->rear = 0;
}
bool isfull(dequeue* pdequeue) {
	return pdequeue->front == (pdequeue->rear + 1) % max_dequeue;
}
bool isempty(dequeue* pdequeue) {
	return pdequeue->front == pdequeue->rear;
}
void addfront(dequeue* pdequeue, data item) {
	if (isfull(pdequeue)) {
		exit(1);
	}
	else if (pdequeue->front == 0)
	{
		pdequeue->items[pdequeue->front] = item;
		pdequeue->rear = pdequeue->rear + 1;
	}
	else
	{
		pdequeue->front = (pdequeue->front - 1 + max_dequeue) % max_dequeue;
		pdequeue->items[pdequeue->front] = item;
	}
}
void addrear(dequeue* pdequeue, data item) {
	if (isfull(pdequeue)) {
		exit(1);
	}
	pdequeue->items[pdequeue->rear] = item;
	pdequeue->rear = (pdequeue->rear + 1) % max_dequeue;
}
void removefront(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	pdequeue->front = (pdequeue->front + 1) % max_dequeue;
}
void removerear(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	pdequeue->rear = (pdequeue->rear - 1 + max_dequeue) % max_dequeue;
}
int peekfront(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	return pdequeue->items[pdequeue->front];
}
int peekrear(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	return pdequeue->items[pdequeue->rear - 1];
}

