#pragma once
#include <QtWidgets/QToolBar>
#include "image.h"

class ToolBar : public QToolBar {
public:
	ToolBar(QWidget* parent, Image* imageLabel);
private:
	void useTool(const int id);
private:
	Image* imageLabel;
};