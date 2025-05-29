#include "main_window.h"
//
#include <QtWidgets/qlayout.h>
#include "cpp_ui/theme/theme_presets.h"
//
#include "cpp_ui/menu_bar.h"
#include "cpp_ui/scale_slider.h"
#include "cpp_ui/tool_bar.h"
#include "cpp_ui/palette.h"
#include "cpp_ui/workspace.h"

MainWindow::MainWindow(const QString& filePath) : QMainWindow(nullptr) {
    resize(720, 480);
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout* centralSpace = new QHBoxLayout;
    QVBoxLayout* tools = new QVBoxLayout;
    //
    Workspace* workspace = new Workspace(this);
    Palette* palette = new Palette(this);
    MenuBar* menuBar = new MenuBar(this, workspace, palette);
    ToolBar* toolBar = new ToolBar(this, workspace, palette);
    ScaleSlider* scaleSlider = new ScaleSlider(this);
    //
    mainLayout->addWidget(menuBar, Qt::AlignTop);
    mainLayout->addLayout(centralSpace, Qt::AlignTop);
    mainLayout->addWidget(scaleSlider, Qt::AlignBottom);
    centralSpace->addLayout(tools, Qt::AlignLeft);
    centralSpace->addWidget(workspace, Qt::AlignRight);
    tools->addWidget(palette, Qt::AlignTop);
    tools->addWidget(toolBar, Qt::AlignBottom);
    //
    scaleSlider->connectTo(std::bind(&Workspace::scale, workspace, std::placeholders::_1));
    //
    setStyleSheet(themePresets::dark);
    //
    if (!filePath.isEmpty()) {
        QImage image = QImage(filePath, nullptr /*format comes from filename*/);
        workspace->setImage(image);
        palette->updateFromImage(image);
        //todo: implement filePath saving
    }
}