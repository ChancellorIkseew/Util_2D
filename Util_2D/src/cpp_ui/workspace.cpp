#include "workspace.h"
//
#include <QtGui/QMouseEvent>
#include <iostream>

Workspace::Workspace(QWidget* parent) : QGraphicsView(parent), _scene(this) {
	setGeometry(200, 200, 32, 32);
	setScene(&_scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Workspace::scale(const int modifier) {
	_scale = static_cast<qreal>(modifier) / 100.0f;
	setTransform(QTransform::fromScale(_scale, _scale), false);
	resize(_image.size() * _scale);
}

void Workspace::mousePressEvent(QMouseEvent* event) {
	QWidget::mousePressEvent(event);
	if (!_item)
		return;
	Qt::MouseButton button = event->button();
	//QPoint itemPos(item->pos().x(), item->pos().y());

	_selectedPixel.setX(static_cast<qreal>(event->pos().x()) / _scale);
	_selectedPixel.setY(static_cast<qreal>(event->pos().y()) / _scale);
	std::cout << "mouse_click" << std::endl;
	std::cout << _selectedPixel.x() << " " << _selectedPixel.y() << '\n';
}

void Workspace::setImage(QImage& image) {
	_image = image;
	QScopedPointer<QGraphicsPixmapItem> ptr(new QGraphicsPixmapItem(QPixmap::fromImage(_image)));
	resize(image.size() * _scale);
	_item.swap(ptr);
	_item->setTransformationMode(Qt::TransformationMode::FastTransformation);
	_scene.addItem(_item.get());
}