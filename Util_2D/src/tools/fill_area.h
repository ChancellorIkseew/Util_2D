#pragma once
#include <QtWidgets/qlabel.h>

void fillArea(QImage& image, QPoint pixel, QRgb color) {
    QRgb preveouseColor = image.pixel(pixel);
    //
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            if (image.pixel(x, y) == preveouseColor)
                image.setPixel(x, y, color);
        }
    }
}