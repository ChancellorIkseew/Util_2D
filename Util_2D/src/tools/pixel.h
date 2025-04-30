#pragma once
#include <QtWidgets/qlabel.h>

void editPixel(QImage& image, QPoint pixel) {
	image.setPixel(pixel, qRgb(255, 255, 255));
}