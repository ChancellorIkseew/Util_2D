#pragma once
#include <QtWidgets/qlabel.h>

static QRgb calculatePixel(const QImage& image, const int startX, const int startY, const int factor) {
    int pixelsCount = 0;
    int redSum = 0;
    int greenSum = 0;
    int blueSum = 0;

    for (int y = startY - factor; y < startY + factor; ++y) {
        for (int x = startX - factor; x < startX + factor; ++x) {
            if (x >= 0 && x < image.width() && y >= 0 && y < image.height()) {
                ++pixelsCount;
                QRgb pixel = image.pixel(x, y);
                redSum += qRed(pixel);
                greenSum += qGreen(pixel);
                blueSum += qBlue(pixel);
            }
        }
    }

    if (pixelsCount == 0)
        return image.pixel(startX, startY);
    return qRgb(redSum / pixelsCount, greenSum / pixelsCount, blueSum / pixelsCount);
}

void blur(QImage& image) {
    QImage newImage(image.size(), image.format());
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            newImage.setPixel(x, y, calculatePixel(image, x, y, 1));
        }
    }
    std::swap(image, newImage);
}
