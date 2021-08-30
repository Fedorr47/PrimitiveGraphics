#include <iostream>

#include "GraphicsTools.h"

using namespace std;
using namespace GraphicsTools;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);

int wmain(int argc, wchar_t* argv[])
{
    TGAImage image(100, 100, TGAImage::RGB);

    {
        Pixel p_start = Pixel(0, 0);
        Pixel p_end = Pixel(100, 100);

        Line line = Line(p_end, p_start);
        DrawLine(line, image, red);
    }
    {
        Pixel p_start = Pixel(0, 100);
        Pixel p_end = Pixel(100, 0);

        Line line = Line(p_end, p_start);
        DrawLine(line, image, green);
    }
    {
        Pixel p_start = Pixel(50, 100);
        Pixel p_end = Pixel(50, 0);

        Line line = Line(p_end, p_start);
        DrawLine(line, image, blue);
    }

    image.flip_vertically();
    image.write_tga_file("lines.tga");
    return 0;
}