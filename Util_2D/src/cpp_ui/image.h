#pragma once
#include <QtWidgets/qlabel.h>
#include <QtGui/QMouseEvent>

class Image : public QLabel {
public:
	Image(QWidget* parent);
	void scale(const int modifier);
	QImage& get() { return image; }
	void set(QImage& qImage);
	QPoint selectedPixel() const { return _selectedPixel; }
private:
	void mousePressEvent(QMouseEvent* event) override final;
public:
	QPoint _selectedPixel;
	QImage image;
	float _scale = 1.0f;
};