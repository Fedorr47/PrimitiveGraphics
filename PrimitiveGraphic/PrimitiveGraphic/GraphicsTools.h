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

	private:
		void Simmetry(
			Pixel origin,
			int X,
			int Y,
			const TGAColor& color
		);
	};
}