#include <iostream>
#include <iomanip>
using namespace std;
// when using multidimensional array , have to write int ex[][x] 
void findStudentAverage(int const scores[][3], double stdAver[], int rowSize, int colSize)
{
    for(int i = 0 ; i < rowSize; i ++ )
    {
        int sum = 0;
        for(int j = 0; j < colSize ; j ++)
        {
            sum +=scores[i][j];
        }
        double average = static_cast<double>(sum) / colSize;
        stdAver[i] = average;
    }
    return;
}
int main()
{
    const int rowSize = 5;
    const int colSize = 3;
    int scores[rowSize][colSize] = {{10,20,30},{40,50,60},{70,80,90},{10,20,30},{40,50,60}};
    double stdAver[rowSize];
    findStudentAverage(scores,stdAver,rowSize,colSize);
    for(int i = 0; i < rowSize; i ++){
        cout << stdAver[i]<<endl;
    }
}