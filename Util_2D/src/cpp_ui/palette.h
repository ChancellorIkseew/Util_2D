#pragma once
#include <QtCore/qset.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/qabstractscrollarea.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtGui/QMouseEvent>

class Palette : public QGraphicsView {
public:
	Palette(QWidget* parent) : QGraphicsView(parent), _scene(this) {
		setFixedWidth(100);
		setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
		setScene(&_scene);
		_scene.addItem(&_item);
		setFrameStyle(QFrame::NoFrame);
		setTransform(QTransform::fromScale(20, 20), false);
		updateLayout();
	}

	void updateFromImage(const QImage& image) {
		colors.clear();
		for (int y = 0; y < image.height(); ++y) {
			for (int x = 0; x < image.width(); ++x) {
				colors.insert(image.pixel(x, y));
			}
		}
		updateLayout();
	}

	QRgb selectedColor() const {
		return _selectedColor;
	}

private:
	void updateLayout() {
		int size = colors.size();
		_palette = QImage(4, size/4 + 1, QImage::Format::Format_ARGB32);

		int i = 0;
		for (const auto& it : colors) {
			_palette.setPixel(QPoint(i % 4, i/4), it);
			++i;
		}

		_item.setPixmap(QPixmap::fromImage(_palette));
	}

	void mousePressEvent(QMouseEvent* event) {
		QGraphicsView::mousePressEvent(event);
		QPoint p = event->pos();
		QPointF pf = mapToScene(p);
		_selectedColor = _palette.pixel(pf.x(), pf.y());
	}

private:
	QGraphicsScene _scene;
	QGraphicsPixmapItem _item;
	QImage _palette;

	QSet<QRgb> colors;
	QRgb _selectedColor = 0;
};