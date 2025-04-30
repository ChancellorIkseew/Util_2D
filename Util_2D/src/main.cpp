
#include <iostream>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
