#include <iostream>
using namespace std;
int& larger(int& x, int& y);
int main()
{
    //pass by reference 참조전달
    int score = 92;
    int& rscore = score;
    cout << score <<endl;
    cout << rscore << endl;
    //참조로 리턴

    int x = 10;
    int y = 20;
    int z = larger(x,y);
    cout << z ;
    
    return 0;
}
int& larger(int& a, int& b){
        if(a > b)
        {
            return a;
        }else{
            return b;
        }
    }