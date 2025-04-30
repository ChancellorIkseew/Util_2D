#pragma once
#include <QtWidgets/QmenuBar>
#include <QtWidgets/qmainwindow.h>
#include "image.h"

class MenuBar : public QMenuBar {
public:
	MenuBar(QMainWindow* parent, Image* image);
private:
	void onOpenFile();
	void setStyle();
private:
	Image* imageLabel;
	QMainWindow* mainWindow;
};