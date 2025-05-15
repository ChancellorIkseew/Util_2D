#pragma once
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qmainwindow.h>
#include "workspace.h"

class MenuBar : public QMenuBar {
public:
	MenuBar(QMainWindow* parent, Workspace* workspace);
private:
	void openFile();
	void saveFile(const QString& filePath);
	void saveFileAs();
	//
	void setStyle();
private:
	QString imageFilePath = "";
	Workspace* workspace;
	QMainWindow* mainWindow;
};