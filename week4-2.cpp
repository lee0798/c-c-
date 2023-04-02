//evaluate postfix notation, converting infix to postfix
/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
void ConvInfixToPostfix(char* exp, char* conExp, int len);
bool ComProirity(int op1, int op2);
int getpriority(char token);
int EvalPostfix(char* exp, int len);
int main()
{

	char r[10] = { '2','3','+','4','*' };
	int size = 5;
	printf("%d", EvalPostfix(r, size));
	return 0;
}


int EvalPostfix(char* exp, int len)
{
	Stack stack;
	int op1, op2;
	InitStack(&stack);
	for (int i = 0; i < len; i++) {
		if (isdigit(exp[i])) // Push an operand.
			Push(&stack, exp[i] - '0');
		else {
			// Evaluate an operator.
			op2 = Peek(&stack), Pop(&stack);
			op1 = Peek(&stack), Pop(&stack);
			if (exp[i] == '+')
				Push(&stack, op1 + op2);
			else if (exp[i] == '-')
				Push(&stack, op1 - op2);
			else if (exp[i] == '*')
				Push(&stack, op1 * op2);
			else if (exp[i] == '/')
				Push(&stack, op1 / op2);
		}
	}
	return Peek(&stack);
}
int main()
{
	char a[100] = { "(4+3)*3" };
	char b[100];
	ConvInfixToPostfix(a, b, 10);
	for (int i = 0; i < 10; i++) {
		if(b[i]=='('||b[i]==')')
		{
			continue;
		}
		printf("%c", b[i]);
	}

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
void ConvInfixToPostfix(char* exp, char* convExp, int len)
{
	Stack stack;
	int idx = 0;
	InitStack(&stack);
	for (int i = 0; i < len; i++)
	{
		if (isdigit(exp[i]))
			convExp[idx++] = exp[i]; // Print an operand.
		else 
		{
			while (!IsEmpty(&stack) && ComProirity(Peek(&stack), exp[i])) 
			{
				convExp[idx++] = Peek(&stack);// Print an operator.
				Pop(&stack); // Pop an operator.
			}
			Push(&stack, exp[i]); // Push an operator.
		}
	}
	while (!IsEmpty(&stack)) {
		convExp[idx++] = Peek(&stack);// Print an operator
		Pop(&stack); // Pop an operator.
	}
}
bool ComProirity(int op1,int op2)
{
	if(getpriority(op1)>=getpriority(op2))
	{
		return true;
	}else
	{
		return false;
	}
}
int getpriority(char token)
{
	switch (token)
	{
	case'(':return 1;
	case')':return 10;
	case'*':
	case'/':return 5;
	case'+':
	case'-':return 2;
	}
}*/

