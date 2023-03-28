//이중 포인터
/*#include <stdio.h>

int main()
{
	char c = 'a';
	char* pc = &c;
	char** ppc = &pc;
	printf("%p %p\n", pc, ppc);
	printf("%p %p\n", &pc, &ppc);
	printf("%d ", sizeof(pc));
	printf("%d\n", sizeof(ppc));

	return 0;
}*/
//array and pointer
/*#include <stdio.h>
int main()
{
	int a[6] = { 5,3,1,2,4,6 };
	int* pa = a;
	printf("%d %d\n", *a, *pa);
	printf("%p %p\n", a, pa);
	printf("%p %p\n", &a, &pa);
	printf("%d %d\n", a[0], pa[0]);
	printf("%d %d\n", a[1], pa[1]);
	return 0;
}*/
//dynamic memory allocation
/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size,i;
	scanf_s("%d", &size);
	int* pn = (int*)malloc(sizeof(int)* size);
	for(i=0;i<size;i++)
	{
		scanf_s("%d", &pn[i]);
	}
	for (i = 0; i < size; i++)
	{
		printf("%d\n", pn[i]);
	}
	free(pn);
	return 0;
}*/
//structure
/*#include <stdio.h>
typedef struct
{
	char name[10];
	int scores[3];
}STUDENT;

int main()
{
	STUDENT s1 = { "Alice",80,70,60 };
	printf("%s\n", s1.name);
	for(int i=0;i<3;i++)
	{
		printf("%d\n", s1.scores[i]);
	}
	return 0;
}*/
// 구조체와 동적할당
/*#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char name[10];
	int scores[3];
	int total;
} STUDENT;

int main()
{
	int n;
	scanf_s("%d", &n);
	STUDENT* s = (STUDENT*)malloc(sizeof(STUDENT) * n);
	for (int i = 0; i < n; i++) {
		scanf_s("%s", s[i].name);
		s[i].total = 0;
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &s[i].scores[j]);
			s[i].total += s[i].scores[j];
		}
		printf("%d", s[i].total);
	}
	free(s);
	return 0;
}*/