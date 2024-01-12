#include <iostream>
using namespace std;
# include <typeinfo>
# include<limits>
# include <iomanip>

int main()
{
    //type promotion
    bool x = true;
    char y = 'A';
    short z = 14;
    float t = 24.5;
    //change type to int have to use typeinfo header
    cout << typeid(x + 100).name();
    cout << typeid(y + 100).name();
    cout << typeid(z + 100).name();
    cout << typeid(t + 100).name()<<endl;
    //explicit type conversion
    cout << static_cast<int>(t) + z << endl;
    //overflow overflow is rotating the range of type
    unsigned int num1 = numeric_limits<unsigned int>::max();
    unsigned int num2 = numeric_limits<unsigned int>::min();
    int num3 = numeric_limits<int>::max();
    cout << num1 + 1<<endl;
    cout << num2 - 1<<endl;
    cout << num3 << endl;
    // noboolalpha(0 || 1), boolalpha(true || false)
    // showbase express the binary expression
    int num4 = 1237;
    cout << oct << num4 <<endl;
    cout << hex << num4 <<endl;
    cout << showbase << oct << num4 <<endl;
    cout << showbase << hex << num4 <<endl;
    //fixed format ussing <iomanip>
    double num5 = 1234.125;
    cout << fixed << setprecision(2) << showpos << setfill('*')<< endl;
    cout << setw(15) << left << num5 << endl;
    cout << setw(15) << right << num5 << endl;
    cout << setw(15) << internal << num5 << endl;


    return 0;
}