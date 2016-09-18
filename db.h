#ifndef DB_H
#define DB_H
#include <QSqlQueryModel>
#include <QSqlDatabase>


class db
{
private:
    static QSqlDatabase connection;

public:
    static QSqlQueryModel* getTradesModel();
    static QSqlQueryModel* getMerchantsNameModel();
    static QSqlQueryModel* getMerchantsModel();
    static QSqlQueryModel* getMerchant(long long id);
    static QSqlQueryModel* getMerchantTrades(long long id);
    static bool insertMerchant(QString name, QString address, QString phone, QString notes);
    static bool newTrade(int merchant_id, QString box_count, QString kilos, QString price_kilo, QString product, QString total, QString date);
    static void openDatabase();
    static void closeDatabase();
};

#endif // DB_H
