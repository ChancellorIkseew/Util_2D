#pragma once
#include <QtGui/qrgba64.h>
#include <QtWidgets/qlabel.h>

class ColorPanel : public QWidget {
public:
	ColorPanel(QWidget* parent);
	void setSelectedColor(const QColor color) { _selectedColor = color; }
	QColor selectedColor() const { return _selectedColor; }
private:
	void updateColor();
	//void mousePressEvent(QMouseEvent* event);

	void setColorBase(const int val);
	void setSaturation(const int val);
	void setTransparency(const int val);

private:
	int colorBase = 0, saturation = 255, transparency = 255;

	QImage _palette;
	QLabel* example;
	QColor _selectedColor = QColor(0, 0, 0, 255);
};