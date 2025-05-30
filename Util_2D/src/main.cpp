#include <QtCore/qdir.h>
#include <QtWidgets/qapplication.h>
#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    //
    QFileInfo exeFileInfo = QCoreApplication::applicationFilePath();
    if (!QDir::setCurrent(exeFileInfo.absolutePath()))
        return app.exec();
    //
    QStringList arguments = QCoreApplication::arguments();
    QString openFilePath = "";
    if (arguments.size() > 1) {
        openFilePath = arguments.at(1);
        QFileInfo openFileInfo(openFilePath);
        if (!openFileInfo.exists() || !openFileInfo.isFile())
            return app.exec();
    }
    //
    MainWindow mainWindow(openFilePath);
    if (!openFilePath.isEmpty())
        QDir::setCurrent(QFileInfo(openFilePath).absoluteDir().absolutePath());
    mainWindow.show();
    //
    return app.exec();
}