#pragma once
#include <set>
#include <QtGui/qrgba64.h>
#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsview.h>

class Palette : public QGraphicsView {
public:
	Palette(QWidget* parent);
	void updateFromImage(const QImage& image);
	void addColor(const QColor color);
	void setSelectedColor(const QColor color) { _selectedColor = color; }
	QColor selectedColor() const { return _selectedColor; }
private:
	void updateLayout();
	void mousePressEvent(QMouseEvent* event);
private:
	QGraphicsScene _scene;
	QGraphicsPixmapItem _item;
	//QGraphicsPixmapItem _frame;
	QImage _palette;

	std::set<QColor> colors;
	QColor _selectedColor = QColor(0, 0, 0, 255);
};