#pragma once
#include <QtWidgets/qlabel.h>
#include <iostream>

void editPixel(QImage& image, QPoint pixel) {
	image.setPixel(pixel, qRgb(255, 255, 255));
}