#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    w.setStyleSheet("bachgroud-image:url(:ap.jpg)");

    return a.exec();
}
