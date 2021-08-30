#pragma once
#include <cstdlib>
#include <memory>
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

	class TgaRender
	{
	private:
		std::shared_ptr<TGAImage> _image;
	public:
		TgaRender(TGAImage InImage)
		{
			_image = std::make_shared<TGAImage>(InImage);
		};

		TGAImage& GetImage()
		{
			return *_image;
		}

		void PutPixel(
			Pixel pixel, 
			const TGAColor& color
		);

		void DrawLine(
			Line line, 
			const TGAColor& color
		);

		void DrawCircle(
			Pixel origin,
			int radius,
			const TGAColor& color
		);
	};

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
	){
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
		int CachedX = origin.X;
		int CachedY = origin.Y;
		int d = 0;
		
		
		PutPixel(Pixel(CachedX + origin.X, CachedY + origin.Y), color);
		PutPixel(Pixel(CachedX + origin.X, -(CachedY + origin.Y)), color);
		PutPixel(Pixel(-(CachedX + origin.X), -(CachedY + origin.Y)), color);
		PutPixel(Pixel(-(CachedX + origin.X), CachedY + origin.Y), color);
		PutPixel(Pixel(CachedY + origin.X, CachedX + origin.Y), color);
		PutPixel(Pixel(CachedY + origin.X, -(CachedX + origin.Y)), color);
		PutPixel(Pixel(-(CachedY + origin.X), -(CachedX + origin.Y)), color);
		PutPixel(Pixel(-(CachedY + origin.X), CachedX + origin.Y), color);
		

	}
}