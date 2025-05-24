#pragma once
#include "tools.h"

void tools::changeContrast(QImage& image) {
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QRgb pixel = image.pixel(x, y);
            int r = qRed(pixel);
            int g = qGreen(pixel);
            int b = qBlue(pixel);

            r = qBound(0, r + 50, 255);
            g = qBound(0, g + 50, 255);
            b = qBound(0, b + 50, 255);

            image.setPixel(x, y, qRgb(r, g, b));
        }
    }
}