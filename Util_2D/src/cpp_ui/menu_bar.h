#pragma once
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qmainwindow.h>
#include "workspace.h"
#include "palette.h"

class MenuBar : public QMenuBar {
public:
	MenuBar(QMainWindow* parent, Workspace* workspace, Palette* palette);
private:
	void openFile();
	void saveFile(const QString& filePath);
	void saveFileAs();
	//
	void setStyle();
private:
	QString imageFilePath = "";
	Workspace* workspace;
	Palette* palette;
	QMainWindow* mainWindow;
};