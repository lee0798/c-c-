//재귀함수
/*#include <stdio.h>
#define size 3
int rsum(int* list,int n);
int main()
{
	int list[size] = { 4,7,5 };
	printf("%d", rsum(list, size));
	return 0;
}
int rsum(int* list, int n)
{
	if (n > 0)
		return rsum(list, n - 1) + list[n - 1];
	else
		return 0;
}*/
//목표숫자 찾기 찾기
#include <stdio.h>
#include <stdlib.h>
int Search(int arr[], int len, int target);
int main()
{
	int size;
	int target;
	printf("배열의 크기는?");
	scanf_s("%d", &size);
	printf("원하는 숫자는?");
	scanf_s("%d", &target);
	int* mainlist = (int*)malloc(sizeof(int) * size);
	printf("숫자 배열을 입력하시오.");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &mainlist[i]);
	}
	printf("%d", Search(mainlist, size, target));
	return 0;
}
int Search(int arr[], int len, int want)
{
	int first = 0;
	int last = len-1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;// Find the middle.
		printf("%d mid 점검\n", mid);
		if (want == arr[mid])
			return mid; // Find the target.
		else { // Otherwise,
			if (want < arr[mid])
			{
				last = mid - 1;
				printf("%d last점검\n",last);
			}
			else
			{
				first = mid + 1;
				printf("%d first점검\n", first);
			}
		}
	}
	return -1; // Return -1 if the target is not found.
}
