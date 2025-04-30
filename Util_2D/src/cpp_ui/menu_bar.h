#pragma once
#include <QtWidgets/QmenuBar>
#include <QtWidgets/qmainwindow.h>
#include "workspace.h"

class MenuBar : public QMenuBar {
public:
	MenuBar(QMainWindow* parent, Workspace* workspace);
private:
	void onOpenFile();
	void setStyle();
private:
	Workspace* workspace;
	QMainWindow* mainWindow;
};