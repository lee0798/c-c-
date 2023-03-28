
//배열로 숫자 넣고 거꾸로 출력하기
/*#include <stdio.h>
#define ARRAY_SIZE 5


int main()
{
    int numbers[ARRAY_SIZE], i;
    printf("Input five numbers\n");
    for(i=0;i<ARRAY_SIZE;i++)
    {
        scanf_s("%d", &numbers[i]);
    }
    for(i=ARRAY_SIZE-1;i>=0;i--)
    {
        printf("%d", numbers[i]);
    }

    return 0;
}*/
//배열의 값의 평균 구하기
/*#include <stdio.h>
#define ARRAY_SIZE 5

void inputnumbers(int num[], int len);
double computeaverage(int num[], int len);

int main()
{
    int numbers[ARRAY_SIZE];
    inputnumbers(numbers, ARRAY_SIZE);
    printf("average: %.3lf", computeaverage(numbers, ARRAY_SIZE));
    return 0;
}
void inputnumbers(int num[], int len)
{
    for(int i=0;i<len ;i++)
    {
        scanf_s("%d", &num[i]);
    }
}
double computeaverage(int num[], int len)
{
    int tmp = 0;
    for(int i=0;i<len;i++)
    {
        tmp = tmp + num[i];
    }
    return tmp / len;

}*/
//2차원 배열 
/*#include <stdio.h>
int main()
{
    int row, col,matrix[6][6];
    for(row=0;row<6;row++)
    {
        for(col=0;col<6;col++)
        {
            if(row==col)
            {
                matrix[row][col] = 0;
            }else if(row>col)
            {
                matrix[row][col] = -1;
            }else
            {
                matrix[row][col] = 1;
            }
            printf("%d", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}*/
// 포인터 reference
/*#include <stdio.h>

int main()
{
    char c = 'A';
    char* pc = &c;
    printf("%c %p\n", c, pc);
    printf("%p %p\n", &c, &pc);
    printf("%d %d\n", sizeof(c), sizeof(pc));
    return 0;
}*/
// 포인터 Dereference
/*#include <stdio.h>
int main()
{
    char c = 'A';
    char* pc = &c;
    printf("%c %c\n", c, *pc);
    *pc = 'C';
    printf("%c %c\n", c, *pc);
    return 0;
}*/
//call by reference
/*#include <stdio.h>
void swap(int* a, int* b);
int main()
{
    int num1, num2;
    num1 = 5, num2 = 1;
    swap(&num1, &num2);
    printf("%d", num1);
    printf("%d", num2);

    return 0;
}
void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}*/
