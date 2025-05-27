#pragma once
#include "tools.h"
#include <list>

static inline bool unique(const QPoint& point, const std::list<QPoint>& spot) {
    return std::find(spot.begin(), spot.end(), point) == spot.end();
}

void tools::fillArea(QImage& image, QPoint pixel, QColor color) {
    QColor preveouseColor = image.pixelColor(pixel);
    if (color == preveouseColor)
        return;
    QPoint imgSize(image.size().width(), image.size().height());
    std::list<QPoint> spot;
    spot.push_back(pixel);
    //
    while (!spot.empty()) {
        QPoint it = spot.front();
        spot.pop_front();
        image.setPixelColor(it, color);
        //
        QPoint up    = it - QPoint(0, 1);
        QPoint down  = it + QPoint(0, 1);
        QPoint left  = it - QPoint(1, 0);
        QPoint right = it + QPoint(1, 0);
        //
        if (up.y() >= 0 && image.pixelColor(up) == preveouseColor && unique(up, spot))
            spot.push_back(up);
        if (down.y() < imgSize.y() && image.pixelColor(down) == preveouseColor && unique(down, spot))
            spot.push_back(down);
        if (left.x() >= 0 && image.pixelColor(left) == preveouseColor && unique(left, spot))
            spot.push_back(left);
        if (right.x() < imgSize.x() && image.pixelColor(right) == preveouseColor && unique(right, spot))
            spot.push_back(right);
    }
}