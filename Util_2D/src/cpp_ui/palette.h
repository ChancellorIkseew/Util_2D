#pragma once
#include <QtCore/qset.h>
#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsview.h>

class Palette : public QGraphicsView {
public:
	Palette(QWidget* parent);
	void updateFromImage(const QImage& image);
	QRgb selectedColor() const { return _selectedColor; }
private:
	void updateLayout();
	void mousePressEvent(QMouseEvent* event);
private:
	QGraphicsScene _scene;
	QGraphicsPixmapItem _item;
	QImage _palette;

	QSet<QRgb> colors;
	QRgb _selectedColor = 0;
};