#include "tool_bar.h"
//
#include <QtWidgets/QInputDialog>
//
#include "tools/tools.h"
//
#include "tool_bar/blur_dialog.h"
#include "palette.h"
#include "workspace.h"

ToolBar::ToolBar(QWidget* parent, Workspace* workspace, Palette* palette) :
	QToolBar(parent), workspace(workspace), palette(palette) {
	setOrientation(Qt::Vertical);
    //
    QIcon pixelIcon("icons/pixel_tool.png");
    QIcon brushIcon("icons/brush_tool.png");
    QIcon fillIcon("icons/fill_tool.png");
    QIcon pipetteIcon("icons/pipette_tool.png");
    QIcon blurIcon("icons/blur_tool.png");
    QIcon contrastIcon("icons/contrast_tool.png");
    QIcon migrationIcon("icons/migration_tool.png");
    QIcon cutIcon("icons/cut_tool.png");
    //
    QAction* pixel = addAction(pixelIcon, "pixel");
    QAction* brush = addAction(brushIcon, "brush");
    QAction* fill = addAction(fillIcon, "fill");
    QAction* pipette = addAction(pipetteIcon, "pipette");
    //
    addAction(blurIcon, "blur", [this]() { setBlur(); });
    addAction(contrastIcon, "contrast", [this]() { toolID = CONTRAST; });
    addAction(migrationIcon, "fast migration", [this]() { toolID = FAST_MIGRATION; });
    addAction(cutIcon, "cut", [this]() { cut(); });
    //
    pixel->setCheckable(true);
    brush->setCheckable(true);
    fill->setCheckable(true);
    pipette->setCheckable(true);
    //
    connect(pixel, &QAction::triggered, [this, pixel, brush, fill, pipette]() {
        toolID = PIXEL;
        pixel->setChecked(true);//
        brush->setChecked(false);
        fill->setChecked(false);
        pipette->setChecked(false);
        });

    connect(brush, &QAction::triggered, [this, pixel, brush, fill, pipette]() {
        toolID = BRUSH;
        pixel->setChecked(false);
        brush->setChecked(true);//
        fill->setChecked(false);
        pipette->setChecked(false);
        });

    connect(fill, &QAction::triggered, [this, pixel, brush, fill, pipette]() {
        toolID = FILL;
        pixel->setChecked(false);
        brush->setChecked(false);
        fill->setChecked(true);//
        pipette->setChecked(false);
        });

    connect(pipette, &QAction::triggered, [this, pixel, brush, fill, pipette]() {
        toolID = PIPETTE;
        pixel->setChecked(false);
        brush->setChecked(false);
        fill->setChecked(false);
        pipette->setChecked(true);//
        });
    //
    toolID = PIXEL;
    pixel->setChecked(true);
    //
    workspace->connectTo(std::bind(&ToolBar::useTool, this));
}


void ToolBar::useTool() {
    tools::useTool(workspace, palette, toolID);
}

void ToolBar::setBlur() {
    QImage& image = workspace->image();
    if (image.isNull())
        return;
    //
    BlurDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted)
        return;
    //
    int radius = dialog.radius();
    switch (dialog.mode()) {
    case BlurMode::BOX:     tools::boxBlur(image, radius);     break;
    case BlurMode::GAUSS:   tools::gaussBlur(image, radius);   break;
    }
    //
    workspace->setImage(image);
}

void ToolBar::cut() {
    QImage& image = workspace->image();
    if (image.isNull())
        return;
    //
    tools::cut(image);
    workspace->setImage(image);
}