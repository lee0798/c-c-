#include <iostream>
using namespace std; 
#include <string>
int main()
{
    std :: cout<< "hello world";
    std :: cout<< "HELLO WORLD "<< std :: endl; //end line
    // can use cout without using std
    int num;
    int num2;
    int sum;
    cout << "first num: " ;
    cin >> num;
    cout << "second num: " ;
    cin >> num2;
    sum =num + num2;
    cout << "sum of num" << sum;
    //constant never change
    const double PI = 3.14;
    cout << "size of short" << sizeof(short int) << "byte" << endl;
    cout << "size of const" << sizeof(PI) << "byte" << endl;
    cout << sizeof(2 + 4);



    
    return 0;
}