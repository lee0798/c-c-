//prefix 식을 계산하는 코드 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


// 추가로 헤더파일이 필요한 경우 자유롭게 추가해도 됩니다.

#define MAX_LEN   100

// 스택 구조체
typedef struct {
	double* arr;
	int top;
} Stack;

// 스택 초기화 함수
void initStack(Stack* pstack, int size)
{
	pstack->arr = (double*)malloc(size * sizeof(double));
	pstack->top = -1;
}
// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* pstack)
{
	return pstack->top == -1;
}

// 스택 삽입 함수
void push(Stack* pstack, double value)
{//error: stack full
	pstack->arr[++(pstack->top)] = value;
}

// 스택 삭제 함수
double pop(Stack* pstack)
{
	if (isEmpty(pstack))
		exit(1); //error: empty stack
	--(pstack->top);
}


// 스택에서 값을 읽어오는 함수
double peek(Stack* pstack)
{
	if (isEmpty(pstack))
		exit(1); //error
	return pstack->arr[pstack->top];
}
// prefix notation 문자열을 계산하는 함수
double prefix_calculate(char* exp)
{
	Stack stack;
	double op1, op2;
	int len = strlen(exp);//문자열의 길이 반환
	initStack(&stack, len);
	for (int i = len - 1; i >= 0; i--)
	{
		if (isdigit(exp[i]))
		{
			// 공백을 건너뛴 후, 두자리 이상의 숫자를 읽어옴
			double numlen = 0;
			double num = 0;
			while (i >= 0 && !isspace(exp[i]))
			{
				num += pow(10, numlen) * (exp[i] - '0');
				numlen++;
				i--;
			}
			push(&stack, num);
		}
		else if (exp[i] == ' ')
		{
			continue;
		}
		else
		{
			//수식기호가 나와을때의 조건
			op2 = peek(&stack), pop(&stack);
			op1 = peek(&stack), pop(&stack);
			if (exp[i] == '+')
				push(&stack, op2 + op1);
			else if (exp[i] == '-')
				push(&stack, op2 - op1);
			else if (exp[i] == '*')
				push(&stack, op2 * op1);
			else if (exp[i] == '/')
				push(&stack, op2 / op1);
		}
	}
	return peek(&stack);
}


int main() {

	// 아래 main 함수는 수정하지 마세요. 
	char expression[MAX_LEN];
	// 개행문자를 제외한 모든 사용자 입력을 받는다는 의미입니다.
	scanf("%[^\n]", expression);

	double result = prefix_calculate(expression);
	printf("%.2lf\n", result);

	return 0;
}


