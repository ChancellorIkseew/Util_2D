#pragma once
#include <QtWidgets/QToolBar>
#include "workspace.h"

class ToolBar : public QToolBar {
public:
	ToolBar(QWidget* parent, Workspace* workspace);
private:
	void useTool();
	void setBlur();
private:
	int toolID = 0;
	Workspace* workspace;
};