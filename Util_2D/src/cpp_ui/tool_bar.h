#pragma once
#include <QtWidgets/QToolBar>

class Palette;
class Workspace;

class ToolBar : public QToolBar {
public:
	ToolBar(QWidget* parent, Workspace* workspace, Palette* palette);
private:
	void useTool();
	void setBlur();
private:
	int toolID;
	Workspace* workspace;
	Palette* palette;
};