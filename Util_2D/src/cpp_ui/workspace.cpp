#include "workspace.h"
//
#include <QtGui/QMouseEvent>
#include <iostream>

Workspace::Workspace(QWidget* parent) : QGraphicsView(parent), _scene(this) {
	setStyleSheet(QString("QWidget {background-color: #1D1D1D; }"));
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	setFrameStyle(QFrame::NoFrame);
	//setDragMode(QGraphicsView::ScrollHandDrag);
	//
	setScene(&_scene);
	_scene.addItem(&_item);
	_item.setTransformationMode(Qt::TransformationMode::FastTransformation);
}

void Workspace::scale(const int modifier) {
	_scale = static_cast<qreal>(modifier) / 100.0;
	setTransform(QTransform::fromScale(_scale, _scale), false);
}

void Workspace::mousePressEvent(QMouseEvent* event) {
	QGraphicsView::mousePressEvent(event);
	QPointF pf = mapToScene(event->pos());
	_selectedPixel = QPoint(pf.x(), pf.y());
	
	if (event->button() == Qt::MouseButton::LeftButton)
		handler();/*
	if (event->button() == Qt::MouseButton::MiddleButton)
		setDragMode(QGraphicsView::RubberBandDrag);*/
}

void Workspace::mouseReleaseEvent(QMouseEvent* event) {
	QGraphicsView::mouseReleaseEvent(event);/*
	if (event->button() == Qt::MouseButton::MiddleButton) {
		_isDragging = false;
		setCursor(Qt::ArrowCursor);
	}*/
}

void Workspace::wheelEvent(QWheelEvent* event) {
	_scale *= event->angleDelta().y() > 0 ? 1.2 : 0.8;
	setTransform(QTransform::fromScale(_scale, _scale), false);
}

void Workspace::setImage(QImage& image) {
	_image = image;
	_item.setPixmap(QPixmap::fromImage(_image));
}