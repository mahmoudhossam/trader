#ifndef UTIL_H
#define UTIL_H
#include <QSqlDatabase>
#include <QApplication>
#include <QSqlQueryModel>
#include <QString>

class util
{
public:
    QSqlDatabase static initializeDatabase();
    void static showMessage(QString str);
    void static db_close();
    QSqlQueryModel static *getMerchantsModel();
    bool static insertMerchant(QString name, QString address, QString phone, QString notes);
    QSqlQueryModel static *getMerchantsNameModel();
};

#endif // UTIL_H
