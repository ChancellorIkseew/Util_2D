#pragma once
#include "tools.h"
#include <list>

static inline bool unique(const QPoint& point, const std::list<QPoint>& spot) {
    return std::find(spot.begin(), spot.end(), point) == spot.end();
}

void tools::fillArea(QImage& image, QPoint pixel, QRgb color) {
    QRgb preveouseColor = image.pixel(pixel);
    QPoint imgSize(image.size().width(), image.size().height());
    //
    std::list<QPoint> spot;
    spot.push_back(pixel);
    //
    while (!spot.empty()) {
        QPoint it = spot.front();
        spot.pop_front();
        image.setPixel(it, color);
        //
        QPoint up    = it - QPoint(0, 1);
        QPoint down  = it + QPoint(0, 1);
        QPoint left  = it - QPoint(1, 0);
        QPoint right = it + QPoint(1, 0);
        //
        if (up.y() >= 0 && image.pixel(up) == preveouseColor && unique(up, spot))
            spot.push_back(up);
        if (down.y() < imgSize.y() && image.pixel(down) == preveouseColor && unique(down, spot))
            spot.push_back(down);
        if (left.x() >= 0 && image.pixel(left) == preveouseColor && unique(left, spot))
            spot.push_back(left);
        if (right.x() < imgSize.x() && image.pixel(right) == preveouseColor && unique(right, spot))
            spot.push_back(right);
    }
}