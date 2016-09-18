#include <QMessageBox>
#include <QString>
#include "util.h"


void util::showMessage(QString str)
{
    QMessageBox mb;
    mb.setText(str);
    mb.exec();
}
