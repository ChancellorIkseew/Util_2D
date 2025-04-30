#include "scale_slider.h"
//
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QIntValidator>
#include <iostream>

static int MIN_SCALE = 1, MAX_SCALE = 10000;

ScaleSlider::ScaleSlider(QWidget* parent) : QWidget(parent) {
    QHBoxLayout* layout = new QHBoxLayout(this);
    setLayout(layout);
    setFixedSize(200, 40);

    slider = new QSlider(Qt::Horizontal, this);
    slider->setBaseSize(200, 20);
    slider->setRange(MIN_SCALE, MAX_SCALE);
    slider->setValue(100);
    layout->addWidget(slider);

    inputField = new QLineEdit(this);
    inputField->setFixedSize(40, 20);
    inputField->setText("100");
    QIntValidator* validator = new QIntValidator(MIN_SCALE, MAX_SCALE, this);
    inputField->setValidator(validator);
    layout->addWidget(inputField);

    connect(slider, &QSlider::valueChanged, this, &ScaleSlider::onSliderMove);
    connect(inputField, &QLineEdit::textEdited, this, &ScaleSlider::onNumberInput);
}


void ScaleSlider::onSliderMove(const int value) {
    inputField->setText(QString::number(value));
    handler(value);
}

void ScaleSlider::onNumberInput(const QString& str) {
    const int value = str.toInt();
    slider->setValue(value);
    handler(value);
}

void ScaleSlider::onMouseWhellMove(QWheelEvent* event) {
    //const int modifier = value / 60;
    const int value = slider->value() + event->angleDelta().y() / 60;
    slider->setValue(value);
    inputField->setText(QString::number(value));
    handler(value);
}
