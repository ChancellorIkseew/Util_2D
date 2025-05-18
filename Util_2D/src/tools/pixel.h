#pragma once
#include <QtWidgets/qlabel.h>

void editPixel(QImage& image, QPoint pixel, QRgb color) {
	image.setPixel(pixel, color);
}