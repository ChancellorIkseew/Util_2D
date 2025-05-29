#pragma once
#include <QtWidgets/qmainwindow.h>

class MainWindow : public QMainWindow {
public:
    MainWindow(const QString& filePath);
};