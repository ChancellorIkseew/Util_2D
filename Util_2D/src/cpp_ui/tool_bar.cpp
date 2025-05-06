#include "tool_bar.h"
//
#include "tools/pixel.h"
#include "tools/blur.h"
#include "tools/contrast.h"
#include "tools/fast_migration.h"

enum Tools {
    PIXEL,
    BRUSH,
    BLUR,
    CONTRAST,
    FAST_MIGRATION,
};

ToolBar::ToolBar(QWidget* parent, Workspace* workspace) :
	QToolBar(parent), workspace(workspace) {
	setOrientation(Qt::Vertical);
    //
    addAction("pixel",          [this]() { toolID = PIXEL; });
    addAction("brush",          [this]() { toolID = BRUSH; });
    addAction("blur",           [this]() { toolID = BLUR; });
    addAction("contrast",       [this]() { toolID = CONTRAST; });
    addAction("fast migration", [this]() { toolID = FAST_MIGRATION; });

    workspace->connectTo(std::bind(&ToolBar::useTool, this));
}


void ToolBar::useTool() {
    QImage& image = workspace->image();
    if (image.isNull())
        return;
    //
    switch (toolID) {
    case PIXEL: editPixel(image, workspace->selectedPixel()); break;
    case BLUR:  blur(image); break;
    case CONTRAST: changeContrast(image); break;
    case FAST_MIGRATION: fastMigration(image, workspace->selectedPixel()); break;
    }
    //
    workspace->setImage(image);
}
