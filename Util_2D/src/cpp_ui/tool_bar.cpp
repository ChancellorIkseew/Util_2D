#include "tool_bar.h"
//
#include "../tools/pixel.h"
#include "../tools/contrast.h"
#include "../tools/fast_migration.h"

enum Tools {
    PIXEL,
    BRUSH,
    BLUR,
    CONTRAST,
    FAST_MIGRATION,
};

ToolBar::ToolBar(QWidget* parent, Image* imageLabel) :
	QToolBar(parent), imageLabel(imageLabel) {
	setOrientation(Qt::Vertical);
    //
    addAction("pixel",          [this]() { useTool(PIXEL); });
    addAction("brush",          [this]() { useTool(BRUSH); });
    addAction("blur",           [this]() { useTool(BLUR); });
    addAction("contrast",       [this]() { useTool(CONTRAST); });
    addAction("fast migration", [this]() { useTool(FAST_MIGRATION); });
}


void ToolBar::useTool(const int id) {
    QImage& image = imageLabel->get();
    if (image.isNull())
        return;
    //
    switch (id) {
    case PIXEL: editPixel(image, imageLabel->selectedPixel()); break;
    case CONTRAST: changeContrast(image); break;
    case FAST_MIGRATION: fastMigration(image, imageLabel->selectedPixel()); break;
    }
    //
    imageLabel->setPixmap(QPixmap::fromImage(image));
}
