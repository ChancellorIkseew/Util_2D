#include "tool_bar.h"
//
#include <QtWidgets/QInputDialog>
//
#include "tools/pixel.h"
#include "tools/box_blur.h"
#include "tools/gauss_blur.h"
#include "tools/contrast.h"
#include "tools/fast_migration.h"
#include "tool_bar/blur_dialog.h"

enum Tools {
    PIXEL,
    BRUSH,
    BLUR,
    CONTRAST,
    FAST_MIGRATION,
};

ToolBar::ToolBar(QWidget* parent, Workspace* workspace, Palette* palette) :
	QToolBar(parent), workspace(workspace), palette(palette) {
	setOrientation(Qt::Vertical);
    //
    addAction("pixel",          [this]() { toolID = PIXEL; });
    addAction("brush",          [this]() { toolID = BRUSH; });
    addAction("blur",           [this]() { setBlur(); });
    addAction("contrast",       [this]() { toolID = CONTRAST; });
    addAction("fast migration", [this]() { toolID = FAST_MIGRATION; });
    //
    workspace->connectTo(std::bind(&ToolBar::useTool, this));
}


void ToolBar::useTool() {
    QImage& image = workspace->image();
    if (image.isNull())
        return;
    //
    switch (toolID) {
    case PIXEL: editPixel(image, workspace->selectedPixel(), palette->selectedColor()); break;
    case CONTRAST: changeContrast(image); break;
    case FAST_MIGRATION: fastMigration(image, workspace->selectedPixel()); break;
    }
    //
    workspace->setImage(image);
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
    case BlurMode::BOX:     boxBlur(image, radius);     break;
    case BlurMode::GAUSS:   gaussBlur(image, radius);   break;
    }
    //
    workspace->setImage(image);
}