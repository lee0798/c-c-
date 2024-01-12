#include<iostream>
using namespace std;
int main()
{
    int arr[5];
    for(int i = 0 ; i < 5 ; i ++)
    {
        cout << "pointer add : " << i;
        cout << arr + i <<endl;
    }
}