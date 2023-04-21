#include <stdio.h>
#include <stdlib.h>
void SWAP(int* a, int* b);
void SelectionSort(int* list, int n);
int main()
{
	int arraysize;
	scanf_s("%d \n", &arraysize);
	int* mainlist = (int*)malloc(sizeof(int) * arraysize);
	for (int i = 0; i < arraysize; i++)
	{
		scanf_s("%d", &mainlist[i]);
	}
	

	SelectionSort(mainlist, arraysize);

	for (int j = 0; j < arraysize; j++)
	{
		printf("% d\n", mainlist[j]);
	}

	free(mainlist);
	return 0;
}

void SelectionSort(int* list, int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[min])
				min = j;
		}
		SWAP(&list[i], &list[min]);
	}
}
void SWAP(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
