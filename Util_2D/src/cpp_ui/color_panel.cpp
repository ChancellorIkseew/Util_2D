#include "color_panel.h"
//
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlayout.h>
#include "scale_slider.h"

ColorPanel::ColorPanel(QWidget* parent) : QWidget(parent) {
	QVBoxLayout* layout = new QVBoxLayout(this);
	setLayout(layout);
	//setFixedSize(100, 200);
	setStyleSheet(QString("QWidget { margin: 0px; }"));

	example = new QLabel(this);
	example->setPixmap(QPixmap(100, 20));
	QLabel* baseColorLabel = new QLabel(this);
	baseColorLabel->setPixmap(QPixmap(100, 10));
	QLabel* saturationLabel = new QLabel(this);
	saturationLabel->setPixmap(QPixmap(100, 10));
	QLabel* transparencyLabel = new QLabel(this);
	transparencyLabel->setPixmap(QPixmap(100, 10));

	ScaleSlider* baseColorSlider = new ScaleSlider(this);
	ScaleSlider* saturationSlider = new ScaleSlider(this);
	ScaleSlider* transparencySlider = new ScaleSlider(this);

	layout->addWidget(example);
	layout->addWidget(baseColorLabel);
	layout->addWidget(baseColorSlider);
	layout->addWidget(saturationLabel);
	layout->addWidget(saturationSlider);
	layout->addWidget(transparencyLabel);
	layout->addWidget(transparencySlider);

	updateColor();



	baseColorSlider->connectTo(std::bind(&ColorPanel::setColorBase, this, std::placeholders::_1));
	saturationSlider->connectTo(std::bind(&ColorPanel::setSaturation, this, std::placeholders::_1));
	transparencySlider->connectTo(std::bind(&ColorPanel::setTransparency, this, std::placeholders::_1));
}

void ColorPanel::setColorBase(const int val) {
	colorBase = val;
	updateColor();
}
void ColorPanel::setSaturation(const int val) {
	saturation = val;
	updateColor();
}
void ColorPanel::setTransparency(const int val) {
	transparency = val;
	updateColor();
}

void ColorPanel::updateColor() {

	QColor color;

	color.setAlpha(transparency);

	int red = 50, blue = 200, green = 50;


	color.setRgb(red, green, blue, transparency);

	QPixmap p(100, 100);
	p.fill(color);
	example->setPixmap(p);
}