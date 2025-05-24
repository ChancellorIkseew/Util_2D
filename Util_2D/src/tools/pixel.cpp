#pragma once
#include "tools.h"

void tools::editPixel(QImage& image, QPoint pixel, QRgb color) {
	image.setPixel(pixel, color);
}