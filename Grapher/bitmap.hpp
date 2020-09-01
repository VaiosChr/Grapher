#ifndef bitmap_hpp
#define bitmap_hpp

#include <cstdint>
#include <memory>
#include <cmath>

using namespace std;

class bitmap
{
private:
    int width{0}, height{0};
    unique_ptr<uint8_t> p_pixels{nullptr};
    
public:
    void graphing_function(double (* func)(double), double x1 = - INFINITY, double x2 = INFINITY);
};

#endif /* bitmap_hpp */
