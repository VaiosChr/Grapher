#include <fstream>
#include <cmath>

#pragma pack(2)

#include "bitmap.hpp"
#include "bitmap_file_header.hpp"
#include "bitmap_info_header.hpp"


void bitmap::run()
{
    draw_axis();
    graphing_function();
    write("picture.bmp");
}

bitmap::bitmap(int width, int height, double(* func)(double)) : width(width), height(height), func(func), p_pixels(new uint8_t[width * height * 3])
{
    y1 = INFINITY;
    y2 = - INFINITY;
    for(int x = x1; x < x2; x++)
    {
        if(func(x) > y2) y2 = func(x);
        if(func(x) < y1) y1 = func(x);
    }
}

void bitmap::graphing_function()
{
    for(int x = x1; x < x2; x++)
    {
//        set_pixel(((x1 > 0 ? (- x1) : x1) + x) * width / (x2 - x1), ((y1 > 0 ? (- y1) : y1) + func(x)) * height / (y2 - y1), 0, 255, 0);
//        ((x1 > 0 ? (- x1) : x1) + x) / (double)(x2 - x1) * width
//        (y1 > 0 ? (- y1) : y1) + func(x) / (double)(y2 - y1) * height
//        set_pixel((double)((x1 > 0 ? (- x1) : x1) + x) / (x2 - x1) * width, (double)((y1 > 0 ? (- y1) : y1) + func(x)) / (y2 - y1) * height, 0, 255, 0);
        set_pixel((abs(x - x1)) * width / (x2 - x1), (func(x) - y1 - 1) * height / (y2 - y1), 0, 255, 0);
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
    if(y1 * y2 <= 0)
    {
        for(int x = 0; x < width; x++) set_pixel(x, - y1 * height / (y2 - y1), 255, 255, 255);
    }
    //draw y axis
    if(x1 * x2 <= 0)
    {
        for(int y = 0; y < height; y++) set_pixel(- x1 * width / (x2 - x1), y, 255, 255, 255);
    }
    //draw (0, 0)
    if(y1 * y2 <= 0 && x1 * x2 <= 0)
    {
        int radius = 5;

        for(int x = - radius; x <= radius; x++)
        {
            int f = sqrt(pow(radius, 2) - pow(x, 2));
            set_pixel(- x1 * width / (x2 - x1) + x, - y1 * height / (y2 - y1) - f, 255, 255, 255);
            set_pixel(- x1 * width / (x2 - x1) + x, - y1 * height / (y2 - y1) + f, 255, 255, 255);        }
    }
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
