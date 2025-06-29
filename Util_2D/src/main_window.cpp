#include "main_window.h"
//
#include <QtWidgets/qlayout.h>
#include "cpp_ui/theme/theme_presets.h"
//
#include "cpp_ui/color_panel.h"
#include "cpp_ui/menu_bar.h"
#include "cpp_ui/scale_slider.h"
#include "cpp_ui/tool_bar.h"
#include "cpp_ui/palette.h"
#include "cpp_ui/workspace.h"

MainWindow::MainWindow(const QString& openFilePath) : QMainWindow(nullptr) {
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
    ColorPanel* colorPanel = new ColorPanel(this);
    ScaleSlider* scaleSlider = new ScaleSlider(this, 200, 10000, 100);
    //
    mainLayout->addWidget(menuBar, Qt::AlignTop);
    mainLayout->addLayout(centralSpace, Qt::AlignTop);
    mainLayout->addWidget(scaleSlider, Qt::AlignBottom);
    centralSpace->addLayout(tools, Qt::AlignLeft);
    centralSpace->addWidget(workspace, Qt::AlignRight);
    tools->addWidget(palette, Qt::AlignTop);
    tools->addWidget(toolBar, Qt::AlignBottom);
    tools->addWidget(colorPanel, Qt::AlignBottom);
    //
    scaleSlider->connectTo(std::bind(&Workspace::scale, workspace, std::placeholders::_1));
    //
    setStyleSheet(themePresets::dark);
    //
    if (!openFilePath.isEmpty()) {
        QImage image = QImage(openFilePath, nullptr /*format comes from filename*/);
        workspace->setImage(image);
        palette->updateFromImage(image);
        //todo: implement filePath saving
    }
}