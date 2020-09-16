#ifndef bitmap_hpp
#define bitmap_hpp

#include <cstdint>
#include <string>

//define the starting (x1) and the ending (x2) x
#define x1 - 1000
#define x2 1000

using namespace std;

class bitmap
{
private:
    int width{0}, height{0};
    double (* func)(double), y1, y2;
    unique_ptr<uint8_t> p_pixels{nullptr};
    
private:
    void graphing_function();
    
    void set_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    
    void draw_axis();
    
    bool write(string filename);

public:
    bitmap(int width, int height, double(* func)(double));
    
    void run();    
};

#endif /* bitmap_hpp */
