#include "image.h"
//
#include <iostream>
//#include <QtWidgets/QGraphicsPixmapItem>

Image::Image(QWidget* parent) : QLabel(parent) {
	setGeometry(200, 200, 32, 32);
	setScaledContents(true);


	//QGraphicsPixmapItem item;
	//item.setTransformationMode(Qt::TransformationMode::FastTransformation);


}

void Image::scale(const int modifier) {
	_scale = static_cast<float>(modifier) / 100.0f;
	resize(image.size() * _scale);
	std::cout << "mod: " << modifier << '\n';
	std::cout << "scale: " << _scale << '\n';
	std::cout << image.width() << '\n';
	std::cout << width() << '\n';
}

void Image::mousePressEvent(QMouseEvent* event) {
	QWidget::mousePressEvent(event);
	Qt::MouseButton button = event->button();
	_selectedPixel = event->pos() / _scale;
	std::cout << "mouse_click" << std::endl;
}

void Image::set(QImage& qImage) {
	image = qImage;
	resize(image.width(), image.height());
	setPixmap(QPixmap::fromImage(image));
}