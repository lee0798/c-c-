//Stack operations
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100
typedef int Data;
typedef struct
{
	Data items[MAX_STACK];
	int top;
}Stack;
void InitStack(Stack* pstack);
bool IsFull(Stack* pstack);
bool IsEmpty(Stack* pstack);
Data Peek(Stack* pstack);
void Push(Stack* pstack,Data items);
void Pop(Stack* pstack);
int main()
{
	Stack s;
	int num;
	InitStack(&s);
	scanf_s("%d", &num);
	Push(&s, num);
	printf("%d\n", IsFull(&s));
	printf("%d\n", IsEmpty(&s));
	printf("%d\n", Peek(&s));
	Pop(&s);
	printf("%d", Peek(&s));

	return 0;
}
void InitStack(Stack* pstack)
{
	pstack->top = -1;
}
bool IsFull(Stack* pstack)
{
	return pstack->top == MAX_STACK - 1;
}
bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}
Data Peek(Stack* pstack)
{
	if (IsEmpty(pstack))
		exit(1); //error: empty stack
	return pstack->items[pstack->top];
}
void Pop(Stack* pstack)
{
	if (IsEmpty(pstack))
		exit(1); //error: empty stack
	--(pstack->top);
}
void Push(Stack* pstack, Data item)
{
	if (IsFull(pstack))
		exit(1); //error: stack full
	pstack->items[++(pstack->top)] = item;
}
// reverse string by using stack
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100
typedef int Data;
typedef struct
{
	Data items[MAX_STACK];
	int top;
}Stack;
void InitStack(Stack* pstack);
bool IsFull(Stack* pstack);
bool IsEmpty(Stack* pstack);
Data Peek(Stack* pstack);
void Push(Stack* pstack, Data items);
void Pop(Stack* pstack);
void ReversePrint(char* s, int len);
int main()
{
	char name[10] = "dohwan";
	ReversePrint(name, 6);
	return 0;
}
void ReversePrint(char* s, int len)
{
	Stack stack;
	char ch;
	InitStack(&stack);// Make a stack empty.
	for (int i = 0; i < len; i++) // Push characters.
		Push(&stack, s[i]);
	while (!IsEmpty(&stack))// Pop characters.
	{
		ch = Peek(&stack);
		printf("%c", ch);
		Pop(&stack);
	}
}
void InitStack(Stack* pstack)
{
	pstack->top = -1;
}
bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}
Data Peek(Stack* pstack)
{
	if (IsEmpty(pstack))
		exit(1); //error: empty stack
	return pstack->items[pstack->top];
}
void Pop(Stack* pstack)
{
	if (IsEmpty(pstack))
		exit(1); //error: empty stack
	--(pstack->top);
}
void Push(Stack* pstack, Data item)
{
	if (IsFull(pstack))
		exit(1); //error: stack full
	pstack->items[++(pstack->top)] = item;
}
//parenthesis Matching function
bool IsParanBalanced(char* exp, int len)
{
	Stack stack;
	InitStack(&stack); // Make a stack empty.
	for (int i = 0; i < len; i++) {
		if (exp[i] == '(') // Check open symbol
			Push(&stack, exp[i]);
		else if (exp[i] == ')') { // Check close symbol
			if (IsEmpty(&stack))
				return false; // Unbalanced case
			else
				Pop(&stack);
		}
	}
	if (IsEmpty(&stack))
		return true; // Balanced case
	else
		return false; // Unbalanced case
}


