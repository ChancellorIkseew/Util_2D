#include "tools.h"

static void perforate(QImage& image) {
    QImage example;
    example.load("data/example.png");
    for (int y = 0; y < 40; ++y) {
        for (int x = 0; x < 40; ++x) {
            if (example.pixelColor(x, y) == Qt::GlobalColor::transparent)
                image.setPixelColor(x, y, Qt::GlobalColor::transparent);
        }
    }
}

void tools::cut(QImage& image) {
    QImage newImage(QSize(40, 40), image.format());

    for (int y = 0; y < 40; ++y) {
        for (int x = 0; x < 40; ++x) {
            int targetX = x - 4, targetY = y - 4;
            if (x < 4) {
                targetX = x + 28;
            }
            else if (x >= 36) {
                targetX = x - 36;
            }
            //
            if (y < 4) {
                targetY = y + 28;
            }
            else if (y >= 36) {
                targetY = y - 36;
            }
            newImage.setPixelColor(x , y, image.pixelColor(targetX, targetY));
        }
    }

    perforate(newImage);
    image = newImage;
}
