#include "GraphicsTools.h"

namespace GraphicsTools
{
	void TgaRender::PutPixel(
		Pixel pixel,
		const TGAColor& color
	)
	{
		_image->set(pixel.X, pixel.Y, color);
	}

	void TgaRender::DrawLine(
		Line line,
		const TGAColor& color
	) {
		int& CachedX0 = line.Begin.X;
		int& CachedY0 = line.Begin.Y;
		int CachedX1 = line.End.X;
		int CachedY1 = line.End.Y;

		int DeltaX = line.DeltaX();
		int DeltaY = -line.DeltaY();

		int SignX = CachedX0 < CachedX1 ? 1 : -1;
		int SignY = CachedY0 < CachedY1 ? 1 : -1;

		int err = DeltaX + DeltaY;
		int err2 = 0;

		while (true)
		{
			PutPixel(line.Begin, color);
			if (CachedX0 == CachedX1 &&
				CachedY0 == CachedY1)
			{
				break;
			}
			err2 = err * 2;
			if (err2 >= DeltaY)
			{
				err += DeltaY;
				CachedX0 += SignX;
			}
			if (err2 <= DeltaX)
			{
				err += DeltaX;
				CachedY0 += SignY;
			}
		}
	}

	void TgaRender::DrawCircle(
		Pixel origin,
		int radius,
		const TGAColor& color
	) {
		int X = 0;
		int Y = radius;
		int Delta = 3 - 2 * Y;
		Simmetry(origin, X, Y, color);

		while (X <= Y)
		{
			++X;	
			if (Delta < 0)
			{
				Delta = Delta + 4 * X + 6;
			}
			else
			{
				Delta = Delta + 4 * (X - Y) + 10;
				--Y;
			}
			Simmetry(origin, X, Y, color);
		}
	}

	inline void TgaRender::Simmetry(
		Pixel origin,
		int X,
		int Y,
		const TGAColor& color
	){
		int XplusX = origin.X + X;
		int YplusY = origin.Y + Y;

		int YminusY = origin.Y - Y;
		int XminusX = origin.X - X;

		int XplusY = origin.X + Y;
		int YplusX = origin.Y + X;

		int XminusY = origin.X - Y;
		int YminusX = origin.Y - X;

		PutPixel(Pixel(XplusX, YplusY), color);
		PutPixel(Pixel(XminusX, YplusY), color);
		PutPixel(Pixel(XplusX, YminusY), color);
		PutPixel(Pixel(XminusX, YminusY), color);
		PutPixel(Pixel(XplusY, YplusX), color);
		PutPixel(Pixel(XminusY, YplusX), color);
		PutPixel(Pixel(XplusY, YminusX), color);
		PutPixel(Pixel(XminusY, YminusX), color);
	}
}