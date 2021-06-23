#include "mainwindow.h"
#include "cpuchart.h"

#include <QApplication>
#include <QtCharts>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();

    return a.exec();
}
