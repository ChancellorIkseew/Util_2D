#include "menu_bar.h"
//
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmessagebox.h>
//
#include "theme/theme_presets.h"
#include "palette.h"
#include "workspace.h"

MenuBar::MenuBar(QMainWindow* parent, Workspace* workspace, Palette* palette) :
	QMenuBar(parent), mainWindow(parent), workspace(workspace), palette(palette) {
	QMenu* file = new QMenu("file", this);
	file->addAction("open", this, &MenuBar::openFile);
	file->addAction("save", [&]() { saveFile(imageFilePath); });
	file->addAction("save as", this, &MenuBar::saveFileAs);
	addMenu(file);

	QMenu* settings = new QMenu("settings", this);
	addMenu(settings);

	QMenu* view = new QMenu("view", this);
	QMenu* theme = new QMenu("theme", view);
	theme->addAction("dark",  [&]() { mainWindow->setStyleSheet(themePresets::dark); });
	theme->addAction("light", [&]() { mainWindow->setStyleSheet(themePresets::light); });
	view->addMenu(theme);
	view->addAction("background color", [&]()
		{
			QColor color = QColor::fromRgb(400);
			QBrush br(color);
			this->workspace->setBackgroundBrush(br);

		});
	addMenu(view);

	setFixedHeight(24);
}

void MenuBar::openFile() {
	QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ""/*dir*/, tr("Image files (*.png *.jpg *.bmp)"));
	if (filePath.isEmpty())
		return;
	QImage image = QImage(filePath, nullptr /*format comes from filename*/);
	workspace->setImage(image);
	palette->updateFromImage(image);
	imageFilePath = filePath;
}

void MenuBar::saveFile(const QString& filePath) {
	if (filePath.isEmpty() || workspace->image().isNull())
		return;
	bool saved = workspace->image().save(filePath);
	if (!saved)
		QMessageBox::critical(this, "Error", "Failed to save image " + filePath);
}

void MenuBar::saveFileAs() {
	if (workspace->image().isNull())
		return;
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), ""/*dir*/, tr("Image files (*.png *.jpg *.bmp);; PNG (*.png);; JPG (*.jpg);; BMP (*.bmp)"));
	saveFile(filePath);
}