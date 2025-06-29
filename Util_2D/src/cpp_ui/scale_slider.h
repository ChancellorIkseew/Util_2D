#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/qslider.h>
#include <QtWidgets/QLineEdit>
#include <QtGui/QMouseEvent>

class ScaleSlider : public QWidget {
using Handler = std::function<void(const int)>;
public:
	ScaleSlider(QWidget* parent, const int size, const int max, const int start);
	void connectTo(Handler handler) {
		this->handler = handler;
	}
	void onMouseWhellMove(QWheelEvent* event);
private:
	void onSliderMove(const int value);
	void onNumberInput(const QString& str);
private:
	QSlider* slider;
	QLineEdit* inputField;
	Handler handler;
};
