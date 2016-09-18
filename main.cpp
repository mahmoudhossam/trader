#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setLayoutDirection(Qt::RightToLeft);
    MainWindow w;
    w.show();

    return a.exec();
}
