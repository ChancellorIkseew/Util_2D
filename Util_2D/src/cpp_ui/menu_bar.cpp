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
		"QMainWindow { background-color: #303030; }"
		//"QPushButton { color: black; background-color: #4CAF50; }"
		//"QPushButton:hover { background-color: #367C39; }"
		"QMenuBar {"
		"    background-color: #1D1D1D;"
		"    color: white;"
		"    border: 2px solid #161616;"
		"}"
		"QMenuBar::item:selected {"
		"    background-color: #3A5986;"
		"    border: 1px solid #4772B3;"
		"    border-radius: 2px;"
		"}"
		"QMenu {"
		"    background-color: #141414;"
		"    color: white;"
		"    border: 1px solid #101010;"
		"}"
		"QMenu::item:selected {"
		"    background-color: #3A5986;"
		"    border: 2px solid #3A5986;"
		"    border-radius: 4px;"
		"}"

		/*
		"QToolBar {"
		"    background-color: #1D1D1D;"
		"    color: white;"
		"    border: 2px solid #161616;"
		"}"*/

	);
}
