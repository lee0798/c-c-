#include <iostream>
using namespace std;
int getSum(const int*, int);
int main()
{
    int arr[5] = {10,20,30,40,50};
    cout << getSum(arr,5);

}
int getSum(const int* p, int size)
{
    int sum = 0;
    for(int i = 0 ; i < size ;i ++)
    {
        sum +=*(p++);
    }
    return sum;
}