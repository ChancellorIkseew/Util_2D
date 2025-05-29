#include "tools.h"
//
#include "cpp_ui/palette.h"
#include "cpp_ui/workspace.h"

void tools::useTool(Workspace* workspace, Palette* palette, const int toolID) {
    QImage& image = workspace->image();
    if (image.isNull())
        return;
    QPoint pixel = workspace->selectedPixel();
    if (pixel.x() < 0 || pixel.y() < 0 || pixel.x() >= image.width() || pixel.y() >= image.height())
        return;
    QColor color = palette->selectedColor();
    if (!color.isValid())
        return;
    //
    switch (toolID) {
    case PIXEL: tools::editPixel(image, pixel, color); break;
    case BRUSH: break;
    case FILL: tools::fillArea(image, pixel, color); break;
    case CONTRAST: tools::changeContrast(image); break;
    case FAST_MIGRATION: tools::fastMigration(image, pixel); break;
    case PIPETTE: tools::pickColor(image, pixel, palette); break;
    }
    //
    workspace->setImage(image);
}