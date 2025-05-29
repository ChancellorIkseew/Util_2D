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
	//_scene.addItem(&_frame);
	_item.setTransformationMode(Qt::TransformationMode::FastTransformation);
	//_frame.setPixmap(QPixmap("icons/arrow_down.png"));
}

void Palette::addColor(const QColor color) {
	colors.insert(color);
	updateLayout();
}

void Palette::updateFromImage(const QImage& image) {
	colors.clear();
	for (int y = 0; y < image.height(); ++y) {
		for (int x = 0; x < image.width(); ++x) {
			colors.insert(image.pixelColor(x, y));
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
		_palette.setPixelColor(QPoint(i % 4, i / 4), it);
		++i;
	}
	//
	_item.setPixmap(QPixmap::fromImage(_palette));
}

void Palette::mousePressEvent(QMouseEvent* event) {
	QGraphicsView::mousePressEvent(event);
	QPointF pf = mapToScene(event->pos());
	_selectedColor = _palette.pixelColor(pf.x(), pf.y());
}

static inline bool operator<(const QColor& a, const QColor& b) {
	return a.rgba64().toArgb32() < b.rgba64().toArgb32();
}