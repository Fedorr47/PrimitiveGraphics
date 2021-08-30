#pragma once
#include <cstdlib>
//TODO: Remove this dependecy later
#include "TGA\TGA.h"

namespace GraphicsTools
{
	struct Pixel
	{
		Pixel(int InX, int InY) :
			X(InX),
			Y(InY)
		{};

		int X{0};
		int Y{0};
	};

	struct Line
	{
		Pixel Begin;
		Pixel End;

		Line(Pixel InBegin, Pixel InEnd) :
			Begin(InBegin),
			End(InEnd)
		{};

		int DeltaX()
		{
			return abs(Begin.X - End.X);
		}

		int DeltaY()
		{
			return abs(Begin.Y - End.Y);
		}
	};

	void DrawLine(
		Line line, 
		TGAImage& image, 
		const TGAColor& color
	){
		int ChashedX0 = line.Begin.X;
		int ChashedY0 = line.Begin.Y;
		int ChashedX1 = line.End.X;
		int ChashedY1 = line.End.Y;

		int DeltaX = line.DeltaX();
		int DeltaY = -line.DeltaY();

		int SignX = ChashedX0 < ChashedX1 ? 1 : -1;
		int SignY = ChashedY0 < ChashedY1 ? 1 : -1;

		int err = DeltaX + DeltaY;
		int err2 = 0;

		while (true)
		{
			image.set(ChashedX0, ChashedY0, color);
			if (ChashedX0 == ChashedX1 &&
				ChashedY0 == ChashedY1)
			{
				break;
			}
			err2 = err * 2;
			if (err2 >= DeltaY)
			{
				err += DeltaY;
				ChashedX0 += SignX;
			}
			if (err2 <= DeltaX)
			{
				err += DeltaX;
				ChashedY0 += SignY;
			}
		}
	}
}