#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //setTitle
    w.setWindowTitle("Qcounter");

    w.show();

    return a.exec();
}
