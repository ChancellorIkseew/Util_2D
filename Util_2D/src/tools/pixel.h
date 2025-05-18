#pragma once
#include <QtWidgets/qlabel.h>
#include <iostream>

void editPixel(QImage& image, QPoint pixel, QRgb color) {
	image.setPixel(pixel, color);
}