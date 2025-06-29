#pragma once
#include <QtWidgets/qlabel.h>

class Palette;
class Workspace;

enum Tools {
    PIXEL,
    BRUSH,
    FILL,
	PIPETTE,
    BLUR,
    CONTRAST,
    FAST_MIGRATION,
};

namespace tools {
	void useTool(Workspace* workspace, Palette* palette, const int toolID);
	//
	void editPixel(QImage& image, QPoint pixel, QColor color);
	void useBrush(QImage& image, QPoint pixel, QRgb color);
	void fillArea(QImage& image, QPoint pixel, QColor color);
	void fastMigration(QImage& image, QPoint pixel);
	void pickColor(QImage& image, QPoint pixel, Palette* palette);
	//
	void cut(QImage& image);
	void boxBlur(QImage& image, const int radius);
	void gaussBlur(QImage& image, const int radius);
	void changeContrast(QImage& image);
}