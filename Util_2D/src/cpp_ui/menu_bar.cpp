#include "menu_bar.h"
//
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmessagebox.h>

MenuBar::MenuBar(QMainWindow* parent, Workspace* workspace) :
	QMenuBar(parent), mainWindow(parent), workspace(workspace) {
	QMenu* file = new QMenu("file", this);
	file->addAction("open", this, &MenuBar::openFile);
	file->addAction("save", this, &MenuBar::saveFile);
	file->addAction("save as", this, &MenuBar::saveFileAs);
	addMenu(file);

	QMenu* settings = new QMenu("settings", this);
	addMenu(settings);

	QMenu* view = new QMenu("view", this);
	view->addAction("style", this, &MenuBar::setStyle);
	addMenu(view);
}

void MenuBar::openFile() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ""/*dir*/, tr("Image files (*.png *.jpg *.bmp)"));
	if (fileName.isEmpty())
		return;
	QImage image = QImage(fileName, nullptr /*format comes from filename*/);
	workspace->setImage(image);
	imageFilePath = fileName;
}

void MenuBar::saveFile() {
	if (imageFilePath.isEmpty())
		return;
	bool saved = workspace->image().save(imageFilePath);
	if (!saved)
		QMessageBox::critical(this, "Error", "Failed to save image " + imageFilePath);
}

void MenuBar::saveFileAs() {
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), ""/*dir*/, tr("Image files (*.png *.jpg *.bmp);; PNG (*.png);; JPG (*.jpg);; BMP (*.bmp)"));
	if (filePath.isEmpty())
		return;
	bool saved = workspace->image().save(filePath);
	if (!saved)
		QMessageBox::critical(this, "Error", "Failed to save image " + filePath);
}

void MenuBar::setStyle() {
	mainWindow->setStyleSheet(
		"QMainWindow { background-color: lightblue; }"         // Main window background
		"QPushButton { color: black; background-color: #4CAF50; }" // Default button style
		"QPushButton:hover { background-color: #367C39; }"       // Hover effect
	);
}
