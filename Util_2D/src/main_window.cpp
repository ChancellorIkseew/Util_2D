#include "main_window.h"
//
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/QFileDialog>
#include <iostream>
#include "cpp_ui/image.h"
#include "cpp_ui/scale_slider.h"
#include "cpp_ui/menu_bar.h"
#include "cpp_ui/tool_bar.h"


MainWindow::MainWindow() : QMainWindow(nullptr) {
    resize(720, 480);
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    setMouseTracking(true);

    Image* image = new Image(this);

    MenuBar* menuBar = new MenuBar(this, image);
    mainLayout->addWidget(menuBar, Qt::AlignTop);
    
    ToolBar* toolBar = new ToolBar(this, image);
    mainLayout->addWidget(toolBar, Qt::AlignTop | Qt::AlignLeft);
    
    ScaleSlider* scaleSlider = new ScaleSlider(this);
    mainLayout->addWidget(scaleSlider, Qt::AlignBottom | Qt::AlignRight);

    scaleSlider->connectTo(std::bind(&Image::scale, image, std::placeholders::_1));
    //connect(this, &MainWindow::wheelEvent, this, &ScaleSlider::onMouseWheelMove);
}



void MainWindow::onButton1Clicked() {
    QMessageBox::information(this, "Button 1", "Button 1 was clicked!");
    std::cout << "ddd\n";
}


void MainWindow::onChange(const int value) {
    std::cout << value << '\n';
}


void MainWindow::wheelEvent(QWheelEvent* event){
    int delta = event->angleDelta().y();
    std::cout << "Wheel event" << delta << '\n';
    QWidget::wheelEvent(event);
}
