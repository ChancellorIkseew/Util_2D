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
    addAction("pixel",          [this]() { useTool(PIXEL); });
    addAction("brush",          [this]() { useTool(BRUSH); });
    addAction("blur",           [this]() { useTool(BLUR); });
    addAction("contrast",       [this]() { useTool(CONTRAST); });
    addAction("fast migration", [this]() { useTool(FAST_MIGRATION); });
}


void ToolBar::useTool(const int id) {
    QImage& image = workspace->image();
    if (image.isNull())
        return;
    //
    switch (id) {
    case PIXEL: editPixel(image, workspace->selectedPixel()); break;
    case BLUR:  blur(image); break;
    case CONTRAST: changeContrast(image); break;
    case FAST_MIGRATION: fastMigration(image, workspace->selectedPixel()); break;
    }
    //
    workspace->setImage(image);
}
