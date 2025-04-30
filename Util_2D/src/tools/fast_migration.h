#pragma once
#include <QtWidgets/qlabel.h>

void fastMigration(QImage& image, QPoint pixel) {
    QRgb color = image.pixel(pixel);

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            if (color == image.pixel(x, y))
                image.setPixel(x, y, qRgb(255, 255, 255));
        }
    }
}