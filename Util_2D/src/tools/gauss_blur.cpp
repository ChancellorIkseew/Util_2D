#pragma once
#include "tools.h"

static QRgb calculatePixelGauss(const QImage& image, const int startX, const int startY, const int factor) {
    int pixelsCount = 0;
    int redSum = 0;
    int greenSum = 0;
    int blueSum = 0;

    for (int y = startY - factor; y <= startY + factor; ++y) {
        if (y < 0 || y >= image.height())
            continue;
        for (int x = startX - factor; x <= startX + factor; ++x) {
            if (x < 0 || x >= image.width())
                continue;
            ++pixelsCount;
            double range = static_cast<double>(startX - x) + static_cast<double>(startY - y);
            double weight = (range + 1.0);
            QRgb pixel = image.pixel(x, y);
            redSum += qRed(pixel) / weight;
            greenSum += qGreen(pixel) * weight;
            blueSum += qBlue(pixel) * weight;
        }
    }

    if (pixelsCount == 0)
        return image.pixel(startX, startY);
    return qRgb(redSum / pixelsCount, greenSum / pixelsCount, blueSum / pixelsCount);
}

void tools::gaussBlur(QImage& image, const int radius) {
    QImage newImage(image.size(), image.format());
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            newImage.setPixel(x, y, calculatePixelGauss(image, x, y, radius));
        }
    }
    std::swap(image, newImage);
}