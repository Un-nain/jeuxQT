#include "MainWindow.h"

#include <QApplication>
#include <QTime>
#include <QGradient>
int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return application.exec();
}
