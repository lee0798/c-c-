#include <iostream>
#include <cmath>
#include<cctype> //stringmethod
#include<ctime> // timemethod 
#include<cstdlib> // random method
using namespace std;
int num2 =5;
int main()
{
    //srand(time(0));
    int temp = rand();
    int num = temp % 10;
    cout << temp << endl;
    cout << num <<endl;
    //Scope resolution Operatorr
    int num2 = 25;
    cout << "num" << ::num2 <<endl;
    cout << "num" << num2 <<endl;


}