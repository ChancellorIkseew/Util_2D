#pragma once
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

class Workspace : public QGraphicsView {
	using Handler = std::function<void()>;
public:
	Workspace(QWidget* parent);
	void scale(const int modifier);
	void connectTo(Handler handler) {
		this->handler = handler;
	}
	QImage& image() { return _image; }
	void setImage(QImage& qImage);
	QPoint selectedPixel() const { return _selectedPixel; }
private:
	void mousePressEvent(QMouseEvent* event) override final;
	void mouseReleaseEvent(QMouseEvent* event) override final;
	void wheelEvent(QWheelEvent* event) override final;
	//
	QPoint relativePos(QPoint pos) const;
public:
	QGraphicsScene _scene;
	QScopedPointer<QGraphicsPixmapItem> _item;

	bool _isDragging = false;
	QPoint _selectedPixel, _lastMousePos;
	QImage _image;
	qreal _scale = 1.0;
	Handler handler;
};