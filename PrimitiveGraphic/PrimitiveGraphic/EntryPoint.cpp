#include <iostream>

#include "GraphicsTools.h"

using namespace std;
using namespace GraphicsTools;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);
const TGAColor greenBlue = TGAColor(0, 255, 255, 255);

#define MAX_WIDTH 800
#define MAX_HEIGHT 800

int wmain(int argc, wchar_t* argv[])
{
    TGAImage image(MAX_WIDTH, MAX_HEIGHT, TGAImage::RGB);
    TgaRender render = TgaRender(image);

    {
        Pixel p_start = Pixel(0, 0);
        Pixel p_end = Pixel(MAX_WIDTH, MAX_HEIGHT);

        Line line = Line(p_end, p_start);
        render.DrawLine(line, red);
    }
    {
        Pixel p_start = Pixel(0, MAX_HEIGHT);
        Pixel p_end = Pixel(MAX_HEIGHT, 0);

        Line line = Line(p_end, p_start);
        render.DrawLine(line, green);
    }
    {
        Pixel p_start = Pixel(MAX_WIDTH/2, MAX_HEIGHT);
        Pixel p_end = Pixel(MAX_WIDTH/2, 0);

        Line line = Line(p_end, p_start);
        render.DrawLine(line, blue);
    }
    {
        Pixel p_origin = Pixel(MAX_WIDTH/2, MAX_HEIGHT/2);
        int p_radius = MAX_HEIGHT/2;

        render.DrawCircle(p_origin, p_radius, greenBlue);
    }

    render.GetImage().flip_vertically();
    render.GetImage().write_tga_file("lines.tga");
    return 0;
}