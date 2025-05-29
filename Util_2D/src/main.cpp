#include <QtCore/qfileinfo.h>
#include <QtWidgets/qapplication.h>
#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    //
    QStringList arguments = QCoreApplication::arguments();
    QString filePath("");
    if (arguments.size() > 1) {
        filePath = arguments.at(1);
        QFileInfo fileInfo(filePath);
        if (!fileInfo.exists() || !fileInfo.isFile())
            return app.exec();
    }
    //
    MainWindow mainWindow(filePath);
    mainWindow.show();
    //
    return app.exec();
}