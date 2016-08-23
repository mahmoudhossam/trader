#ifndef DB_H
#define DB_H
#include <QSqlQueryModel>
#include <QSqlDatabase>


class db
{
private:
    static QSqlDatabase connection;

public:
    static QSqlQueryModel* getMerchantsModel();
    static QSqlQueryModel* getMerchantsNameModel();
    static bool insertMerchant(QString name, QString address, QString phone, QString notes);
    static void openDatabase();
    static void closeDatabase();
};

#endif // DB_H
