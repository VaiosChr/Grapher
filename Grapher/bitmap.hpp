#ifndef bitmap_hpp
#define bitmap_hpp

#include <cstdint>
#include <memory>
#include <string>

#define x1 - 1000
#define x2 1000

using namespace std;

class bitmap
{
private:
    int width{0}, height{0};
    unique_ptr<uint8_t> p_pixels{nullptr};
    
public:
    void run();
    
    bitmap(int width, int height);
    
    void graphing_function(double (* func)(double));
    
    void set_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    
    void draw_axis();
    
    bool write(string filename);
};

#endif /* bitmap_hpp */
