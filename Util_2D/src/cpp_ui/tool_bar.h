#pragma once
#include <QtWidgets/QToolBar>
#include "workspace.h"

class ToolBar : public QToolBar {
public:
	ToolBar(QWidget* parent, Workspace* workspace);
private:
	void useTool(const int id);
private:
	Workspace* workspace;
};