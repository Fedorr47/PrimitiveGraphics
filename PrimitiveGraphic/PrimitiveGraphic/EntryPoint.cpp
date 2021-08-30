#include <iostream>

#include "GraphicsTools.h"

using namespace std;
using namespace GraphicsTools;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);
const TGAColor greenBlue = TGAColor(0, 255, 255, 255);

int wmain(int argc, wchar_t* argv[])
{
    TGAImage image(100, 100, TGAImage::RGB);
    TgaRender render = TgaRender(image);

    //{
    //    Pixel p_start = Pixel(0, 0);
    //    Pixel p_end = Pixel(100, 100);

    //    Line line = Line(p_end, p_start);
    //    render.DrawLine(line, red);
    //}
    //{
    //    Pixel p_start = Pixel(0, 100);
    //    Pixel p_end = Pixel(100, 0);

    //    Line line = Line(p_end, p_start);
    //    render.DrawLine(line, green);
    //}
    //{
    //    Pixel p_start = Pixel(50, 100);
    //    Pixel p_end = Pixel(50, 0);

    //    Line line = Line(p_end, p_start);
    //    render.DrawLine(line, blue);
    //}
    {
        Pixel p_origin = Pixel(50, 50);
        int p_radius = 50;

        render.DrawCircle(p_origin, p_radius, red);
    }

    render.GetImage().flip_vertically();
    render.GetImage().write_tga_file("lines.tga");
    return 0;
}