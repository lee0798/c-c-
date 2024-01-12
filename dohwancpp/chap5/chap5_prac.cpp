# include <iostream>
using namespace std ;
#include <fstream>
int main()
{
    //while
    int sum = 0;
    int num;
    ifstream infile ;
    //open file
    infile.open("numbers.dat");
    //while 
    while(infile >> num)
    {
        sum = sum + num;
    }
    // output of result
    cout << sum;
    infile.close();
    return 0; 
}