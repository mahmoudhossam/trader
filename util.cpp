#include "util.h"
#include <QMessageBox>
#include <QString>


void util::showMessage(QString str)
{
    QMessageBox mb;
    mb.setText(str);
    mb.exec();
}
