# ifndef CIRCLE_H
# define CIRCLE_H
# include <iostream>
#include <cassert>
# include "Circle.h"
using namespace std;
class Circle
{
    private : 
        double radius;
    public :
        Circle(double radius);
        Circle();
        Circle(const Circle& circle)
        ~Circle();
        void setRadius() const;
        


};
#endif