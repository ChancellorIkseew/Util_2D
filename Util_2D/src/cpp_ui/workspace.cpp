#include "workspace.h"
//
#include <QtGui/QMouseEvent>
#include <iostream>

static QPoint _mousePos;
static QPoint _startDraggingPos;


Workspace::Workspace(QWidget* parent) : QGraphicsView(parent), _scene(this) {
	setStyleSheet(QString("QWidget {background-color: #1D1D1D; }"));
	setScene(&_scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFrameStyle(QFrame::NoFrame);
}

void Workspace::scale(const int modifier) {
	_scale = static_cast<qreal>(modifier) / 100.0;
	setTransform(QTransform::fromScale(_scale, _scale), false);
}

void Workspace::mousePressEvent(QMouseEvent* event) {
	QGraphicsView::mousePressEvent(event);
	if (!_item)
		return;
	Qt::MouseButton button = event->button();
	_mousePos = relativePos(event->pos());

	_selectedPixel.setX(_image.size().width() / 2 + static_cast<qreal>(_mousePos.x()) / _scale);
	_selectedPixel.setY(_image.size().height() / 2 + static_cast<qreal>(_mousePos.y()) / _scale);
	
	//std::cout << _selectedPixel.x() << " " << _selectedPixel.y() << '\n';
	/*
	if (!_isDragging)
		_startDraggingPos = _mousePos;

	if (_isDragging) {
		QPoint delta = _startDraggingPos - _mousePos;
		std::cout << "delta " << delta.x() << " " << delta.y() << '\n';
		
	}
	*/
	if (event->button() == Qt::MouseButton::LeftButton)
		handler();
	if (event->button() == Qt::MouseButton::MiddleButton)
		_isDragging = true;

	std::cout << "size " << size().width() << " " << size().height() << '\n';
	std::cout << "pos " << event->pos().x() << " " << event->pos().y() << '\n';
	std::cout << "rel " << _mousePos.x() << " " << _mousePos.y() << '\n';

}

void Workspace::mouseReleaseEvent(QMouseEvent* event) {
	QGraphicsView::mouseReleaseEvent(event);
	if (event->button() == Qt::MouseButton::MiddleButton)
		_isDragging = false;
}

void Workspace::wheelEvent(QWheelEvent* event) {
	_scale *= event->angleDelta().y() > 0 ? 1.2 : 0.8;
	setTransform(QTransform::fromScale(_scale, _scale), false);
}

QPoint Workspace::relativePos(QPoint pos) const {
	return pos - QPoint(size().width(), size().height()) / 2;
}

void Workspace::setImage(QImage& image) {
	_image = image;
	QScopedPointer<QGraphicsPixmapItem> ptr(new QGraphicsPixmapItem(QPixmap::fromImage(_image)));
	_item.swap(ptr);
	_item->setTransformationMode(Qt::TransformationMode::FastTransformation);
	_scene.addItem(_item.get());
}