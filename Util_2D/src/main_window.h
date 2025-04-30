#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qslider.h>
#include <QtGui/QMouseEvent>
#include <iostream>

class MainWindow : public QMainWindow {
public:
    MainWindow();
private:
    void onButton1Clicked();
    //
    void onChange(const int value);

    void wheelEvent(QWheelEvent* event) override final;
};
