#include <fstream>

#include "bitmap.hpp"
#include "bitmap_file_header.hpp"
#include "bitmap_info_header.hpp"

void run()
{
    
}

bitmap::bitmap(int width, int height) : width(width), height(height), p_pixels(new uint8_t[width * height * 3]){}

void bitmap::graphing_function(double (* func)(double))
{
    for(int x = x1; x < x2; x++)
    {
        #warning do something with func
    }
}

void bitmap::set_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t * pixel = p_pixels.get();
    
    pixel += 3 * y * width + 3 * x;
    pixel[0] = red;
    pixel[1] = green;
    pixel[2] = blue;
}

void bitmap::draw_axis()
{
    //draw x axis
    for(int x = 0; x < width; x++) set_pixel(x, height / 2, 255, 255, 255);
    //draw y axis
    for(int y = 0; y < height; y++) set_pixel(width / 2, y, 255, 255, 255);
}

bool bitmap::write(string filename)
{
    bitmap_file_header file_header;
    bitmap_info_header info_header;
    
    file_header.file_size = sizeof(bitmap_file_header) + sizeof(bitmap_info_header) + width * height * 3;
    file_header.data_offset = sizeof(bitmap_file_header) + sizeof(bitmap_info_header);
    
    info_header.width = width;
    info_header.height = height;
    ofstream file;
    file.open(filename, ios::out|ios::binary);
    if(!file) return false;
    file.write((char *)&file_header, sizeof(file_header));
    file.write((char *)&info_header, sizeof(info_header));
    file.write((char *)p_pixels.get(), width * height * 3);
    
    file.close();
    if(!file) return false;
    return true;
}
