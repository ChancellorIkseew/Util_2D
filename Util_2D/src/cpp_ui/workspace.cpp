#include "workspace.h"
//
#include <QtGui/QMouseEvent>
#include <iostream>

Workspace::Workspace(QWidget* parent) : QGraphicsView(parent), _scene(this) {
	setStyleSheet(QString("QWidget {background-color: #1D1D1D; }"));
	setScene(&_scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	setFrameStyle(QFrame::NoFrame);
}

void Workspace::scale(const int modifier) {
	_scale = static_cast<qreal>(modifier) / 100.0;
	setTransform(QTransform::fromScale(_scale, _scale), false);
	//QTransform tr = QTransform(_scale, 0, 0, _scale, 100, 100);
	//setTransform(tr, false);
}

void Workspace::mousePressEvent(QMouseEvent* event) {
	QGraphicsView::mousePressEvent(event);
	if (!_item)
		return;
	QPoint p = event->pos();
	QPointF pf = mapToScene(p);
	_selectedPixel = QPoint(pf.x(), pf.y());
	
	if (event->button() == Qt::MouseButton::LeftButton)
		handler();
	if (event->button() == Qt::MouseButton::MiddleButton) {
		_isDragging = true;
		setCursor(Qt::ClosedHandCursor);
	}
}

void Workspace::mouseReleaseEvent(QMouseEvent* event) {
	QGraphicsView::mouseReleaseEvent(event);
	if (event->button() == Qt::MouseButton::MiddleButton) {
		_isDragging = false;
		setCursor(Qt::ArrowCursor);
	}
}

void Workspace::mouseMoveEvent(QMouseEvent* event) {
	if (!_isDragging)
		return;
	//scroll(event->pos().x() / 2, event->pos().y() / 2);
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