//재귀함수 
/*#include<stdio.h>
int rsum(int n);
int main() 
{
	int num;
	scanf_s("%d", &num);
	printf("%d", rsum(num));
	return 0;
}
int rsum(int n)
{
	if(n==0)
	{
		return 0;
	}
	else if(n%3!=0)
	{
		return rsum(n - n % 3);
	}else
	{
		return rsum(n - 3) + n;
	}
}*/
//finding the maximum
/*#include <stdio.h>
#define size 6
int rfindMax(int* arr, int n);
int main()
{
	int list[size] = { 10,4,7,2,8,9 };
	printf("%d", rfindMax(list, size));
	return 0;
}
int rfindMax(int* arr, int n)
{
	if (n == 1)
		return arr[0];
	else
	{
		int max = rfindMax(arr, n - 1);
		if (max < arr[n - 1])
			return arr[n - 1];
		else
			return max;
	}
}*/
//fibonacci numbers n번째 숫자 찾기
/*#include<stdio.h>
int fibo(int n);
int main()
{
	int num;
	scanf_s("%d", &num);
	printf("%d", fibo(num));
	return 0;
}
int fibo(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}else 
	{
		int pre=1, cur=1, nex=1;
		for(int i=3;i<n+1;i++)
		{
			pre = cur, cur = nex;
			nex = pre + cur;
		}
		return nex;
	}
}*/
//fibonacci numbers n번째 숫자 찾기2 재귀함수 ver
 /*int rfibo(int n)
{
if (n == 1 || n == 2) 
{
	return 1;
}else
{
	return rfibo(n - 1) + rfibo(n - 2);
}
}*/
