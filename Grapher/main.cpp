#include <iostream>
#include <cmath>

#include "bitmap.hpp"

using namespace std;

double my_function(double x)
{
    //replace the following line with your function
    double f = pow(x, 3);
    
    return f;
}

int main()
{
    double (* p_func)(double) = my_function;
//    bitmap bmp;
//
//    bmp.graphing_function(p_func);
    
    return 0;
}
