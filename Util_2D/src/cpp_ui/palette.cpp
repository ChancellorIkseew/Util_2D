#include "palette.h"
//
#include <QtGui/qevent.h>

Palette::Palette(QWidget* parent) : QGraphicsView(parent), _scene(this) {
	setFixedWidth(100);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	setFrameStyle(QFrame::NoFrame);
	setTransform(QTransform::fromScale(20, 20), false);
	//
	setScene(&_scene);
	_scene.addItem(&_item);
	_item.setTransformationMode(Qt::TransformationMode::FastTransformation);
}

void Palette::updateFromImage(const QImage& image) {
	colors.clear();
	for (int y = 0; y < image.height(); ++y) {
		for (int x = 0; x < image.width(); ++x) {
			colors.insert(image.pixel(x, y));
		}
	}
	updateLayout();
}

void Palette::updateLayout() {
	int size = colors.size();
	_palette = QImage(4, size / 4 + 1, QImage::Format::Format_ARGB32);
	//
	int i = 0;
	for (const auto& it : colors) {
		_palette.setPixel(QPoint(i % 4, i / 4), it);
		++i;
	}
	//
	_item.setPixmap(QPixmap::fromImage(_palette));
}

void Palette::mousePressEvent(QMouseEvent* event) {
	QGraphicsView::mousePressEvent(event);
	QPointF pf = mapToScene(event->pos());
	_selectedColor = _palette.pixel(pf.x(), pf.y());
}