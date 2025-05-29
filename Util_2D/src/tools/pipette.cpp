#include "tools.h"
#include "cpp_ui/palette.h"

void tools::pickColor(QImage& image, QPoint pixel, Palette* palette) {
	palette->setSelectedColor(image.pixelColor(pixel));
}