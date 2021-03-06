#include <iostream>
#include <cmath>

#include "bitmap.hpp"

#define width 2000
#define height 1500

using namespace std;

double my_function(double x)
{
    //replace the following line with your function and modify the x1 and x2 at bitmap.hpp to be the starting and ending x respectively
    double f = pow(x, 3);
    
    return f;
}

int main()
{
    double (* p_func)(double) = my_function;
    bitmap bmp(width, height, p_func);

    bmp.run();
    cout << "Finished!" << endl;
    
    return 0;
}
