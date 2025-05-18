#include "main_window.h"
//
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/QFileDialog>
#include <iostream>
#include "cpp_ui/workspace.h"
#include "cpp_ui/scale_slider.h"
#include "cpp_ui/menu_bar.h"
#include "cpp_ui/tool_bar.h"
#include "cpp_ui/palette.h"


MainWindow::MainWindow() : QMainWindow(nullptr) {
    resize(720, 480);
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    setMouseTracking(true);
    //
    Workspace* workspace = new Workspace(this);
    Palette* palette = new Palette(this);
    MenuBar* menuBar = new MenuBar(this, workspace, palette);
    ToolBar* toolBar = new ToolBar(this, workspace, palette);
    ScaleSlider* scaleSlider = new ScaleSlider(this);
    //
    mainLayout->addWidget(menuBar, Qt::AlignTop);
    mainLayout->addWidget(toolBar, Qt::AlignTop | Qt::AlignLeft);
    mainLayout->addWidget(palette, Qt::AlignTop | Qt::AlignLeft);
    mainLayout->addWidget(scaleSlider, Qt::AlignBottom | Qt::AlignRight);
    //
    scaleSlider->connectTo(std::bind(&Workspace::scale, workspace, std::placeholders::_1));
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
