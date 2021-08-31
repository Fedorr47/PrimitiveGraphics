#pragma once

//void TgaRender::DrawCircle(
	//	Pixel origin,
	//	int radius,
	//	const TGAColor& color
	//) {
	//	int x0 = origin.X;
	//	int y0 = origin.Y;
	//	int x = 0;
	//	int y = radius;
	//	int delta = 1 - 2 * radius;
	//	int error = 0;
	//	while (y >= 0) {
	//		PutPixel(Pixel(x0 + x, y0 + y), color);
	//		PutPixel(Pixel(x0 + x, y0 - y), color);
	//		PutPixel(Pixel(x0 - x, y0 + y), color);
	//		PutPixel(Pixel(x0 - x, y0 - y), color);
	//		error = 2 * (delta + y) - 1;
	//		if (delta < 0 && error <= 0) {
	//			++x;
	//			delta += 2 * x + 1;
	//			continue;
	//		}
	//		error = 2 * (delta - x) - 1;
	//		if (delta > 0 && error > 0) {
	//			--y;
	//			delta += 1 - 2 * y;
	//			continue;
	//		}
	//		++x;
	//		delta += 2 * (x - y);
	//		--y;
	//	}
	//}