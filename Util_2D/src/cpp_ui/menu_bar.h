#pragma once
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qmainwindow.h>
#include "workspace.h"

class MenuBar : public QMenuBar {
public:
	MenuBar(QMainWindow* parent, Workspace* workspace);
private:
	void openFile();
	void saveFile();
	void saveFileAs();
	//
	void setStyle();
private:
	Workspace* workspace;
	QMainWindow* mainWindow;
};