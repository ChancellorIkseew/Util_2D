#include "menu_bar.h"
//
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/QFileDialog>
#include <iostream>

MenuBar::MenuBar(QMainWindow* parent, Image* imageLabel) :
	QMenuBar(parent), mainWindow(parent), imageLabel(imageLabel) {
	QMenu* file = new QMenu("file", this);
	file->addAction("open", this, &MenuBar::onOpenFile);
	file->addAction("save");
	file->addAction("save as");
	addMenu(file);

	QMenu* settings = new QMenu("settings", this);
	addMenu(settings);

	QMenu* view = new QMenu("view", this);
	view->addAction("style", this, &MenuBar::setStyle);
	addMenu(view);
}

void MenuBar::onOpenFile() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
	if (fileName.isEmpty())
		return;
	QImage qImage = QImage(fileName, nullptr /*format comes from filename*/);
	imageLabel->set(qImage);
}

void MenuBar::setStyle() {
	mainWindow->setStyleSheet(
		"QMainWindow { background-color: lightblue; }"         // Main window background
		"QPushButton { color: black; background-color: #4CAF50; }" // Default button style
		"QPushButton:hover { background-color: #367C39; }"       // Hover effect
	);
}