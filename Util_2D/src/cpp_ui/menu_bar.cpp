#include "menu_bar.h"
//
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmessagebox.h>

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
	view->addAction("style", this, &MenuBar::setStyle);
	addMenu(view);
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
	if (filePath.isEmpty())
		return;
	bool saved = workspace->image().save(filePath);
	if (!saved)
		QMessageBox::critical(this, "Error", "Failed to save image " + filePath);
}

void MenuBar::saveFileAs() {
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), ""/*dir*/, tr("Image files (*.png *.jpg *.bmp);; PNG (*.png);; JPG (*.jpg);; BMP (*.bmp)"));
	saveFile(filePath);
}

void MenuBar::setStyle() {
	mainWindow->setStyleSheet(
		"QMainWindow { background-color: lightblue; }"         // Main window background
		"QPushButton { color: black; background-color: #4CAF50; }" // Default button style
		"QPushButton:hover { background-color: #367C39; }"       // Hover effect
	);
}
