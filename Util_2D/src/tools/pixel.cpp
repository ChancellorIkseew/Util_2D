#pragma once
#include "tools.h"

void tools::editPixel(QImage& image, QPoint pixel, QColor color) {
	image.setPixelColor(pixel, color);
}