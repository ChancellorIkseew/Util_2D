#include "tool_bar.h"
//
#include <QtWidgets/QInputDialog>
//
#include "tools/pixel.h"
#include "tools/fill_area.h"
#include "tools/box_blur.h"
#include "tools/gauss_blur.h"
#include "tools/contrast.h"
#include "tools/fast_migration.h"
//
#include "tool_bar/blur_dialog.h"

enum Tools {
    PIXEL,
    BRUSH,
    FILL,
    BLUR,
    CONTRAST,
    FAST_MIGRATION,
};

ToolBar::ToolBar(QWidget* parent, Workspace* workspace, Palette* palette) :
	QToolBar(parent), workspace(workspace), palette(palette) {
	setOrientation(Qt::Vertical);
    //
    QIcon pixelIcon("icons/pixel_tool.png");
    QIcon brushIcon("icons/brush_tool.png");
    QIcon fillIcon("icons/fill_tool.png");
    QIcon blurIcon("icons/blur_tool.png");
    QIcon contrastIcon("icons/contrast_tool.png");
    QIcon migrationIcon("icons/migration_tool.png");
    //
    addAction(pixelIcon,    "pixel",           [this]() { toolID = PIXEL; });
    addAction(brushIcon,    "brush",           [this]() { toolID = BRUSH; });
    addAction(fillIcon,     "fill",            [this]() { toolID = FILL; });
    addAction(blurIcon,     "blur",            [this]() { setBlur(); });
    addAction(contrastIcon, "contrast",        [this]() { toolID = CONTRAST; });
    addAction(migrationIcon,"fast migration",  [this]() { toolID = FAST_MIGRATION; });
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
    case FILL: fillArea(image, workspace->selectedPixel(), palette->selectedColor()); break;
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