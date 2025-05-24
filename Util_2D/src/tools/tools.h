#pragma once
#include <QtWidgets/qlabel.h>

namespace tools {
	void editPixel(QImage& image, QPoint pixel, QRgb color);
	void useBrush(QImage& image, QPoint pixel, QRgb color);
	void fillArea(QImage& image, QPoint pixel, QRgb color);
	void fastMigration(QImage& image, QPoint pixel);

	void boxBlur(QImage& image, const int radius);
	void gaussBlur(QImage& image, const int radius);
	void changeContrast(QImage& image);
}