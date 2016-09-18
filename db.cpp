#include <QString>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>
#include "db.h"

QSqlDatabase db::connection;

QSqlQueryModel* db::getTradesModel()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query_text = "select m.merchant_name, t.box_count, t.kilos, "
                         "t.price_kilo, t.product, t.total, t.date "
                         "FROM trades t INNER JOIN merchants m ON t.merchant_id = m.id;";
    QSqlQuery query(query_text, connection);
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "إسم");
    model->setHeaderData(1, Qt::Horizontal, "صندوق");
    model->setHeaderData(2, Qt::Horizontal, "كيلو");
    model->setHeaderData(3, Qt::Horizontal, "سعر الكيلو");
    model->setHeaderData(4, Qt::Horizontal, "الصنف");
    model->setHeaderData(5, Qt::Horizontal, "الإجمالى");
    model->setHeaderData(6, Qt::Horizontal, "التاريخ");
    return model;
}

bool db::insertMerchant(QString name, QString address, QString phone, QString notes)
{
    QSqlQuery query(connection);
    query.prepare("INSERT INTO merchants (merchant_name, address, phone, notes) VALUES (?, ?, ?, ?);");
    query.bindValue(0, name);
    query.bindValue(1, address);
    query.bindValue(2, phone);
    query.bindValue(3, notes);
    return query.exec();
}

bool db::newTrade(int merchant_id, QString box_count, QString kilos, QString price_kilo, QString product, QString total, QString date)
{
    QSqlQuery query(connection);
    query.prepare("INSERT INTO trades (merchant_id, box_count, kilos, price_kilo, product, total, date) VALUES (?, ?, ?, ?, ?, ?, ?);");
    query.addBindValue(merchant_id);
    query.addBindValue(box_count);
    query.addBindValue(kilos);
    query.addBindValue(price_kilo);
    query.addBindValue(product);
    query.addBindValue(total);
    query.addBindValue(date);
    return query.exec();

}

QSqlQueryModel* db::getMerchantsNameModel()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query_text = "select merchant_name FROM merchants;";
    QSqlQuery query(query_text, connection);
    model->setQuery(query);
    return model;
}

QSqlQueryModel* db::getMerchantsModel()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query_text = "select * FROM merchants";
    QSqlQuery query(query_text, connection);
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "رقم");
    model->setHeaderData(1, Qt::Horizontal, "إسم");
    model->setHeaderData(2, Qt::Horizontal, "تليفون");
    model->setHeaderData(3, Qt::Horizontal, "عنوان");
    model->setHeaderData(4, Qt::Horizontal, "ملاحظات");
    return model;
}

QSqlQueryModel* db::getMerchant(long long id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query_text = "select * from merchants where id = " + QString::number(id);
    QSqlQuery query(query_text, connection);
    model->setQuery(query);
    return model;
}

QSqlQueryModel* db::getMerchantTrades(long long id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query_text = "select t.box_count, t.kilos, t.price_kilo, t.product, t.total, t.date"
                         " from trades t INNER JOIN merchants m on m.id = t.merchant_id where t.merchant_id = " + QString::number(id);
    QSqlQuery query(query_text, connection);
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "عدد");
    model->setHeaderData(1, Qt::Horizontal, "كيلو");
    model->setHeaderData(2, Qt::Horizontal, "سعر الكيلو");
    model->setHeaderData(3, Qt::Horizontal, "الصنف");
    model->setHeaderData(4, Qt::Horizontal, "الإجمالى");
    model->setHeaderData(5, Qt::Horizontal, "التاريخ");
    return model;
}

void db::openDatabase()
{
    QDir path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    // create writable location if it doesn't exist
    if(!path.exists())
    {
        path.mkpath(path.absolutePath());
    }
    QFileInfo db_path = path.absolutePath() + "/trade.db";
    if(!connection.isOpen())
    {
        // This looks for the db in the appdata folder and creates it if it doesn't exist
        connection = QSqlDatabase::addDatabase("QSQLITE");
        connection.setDatabaseName(db_path.absoluteFilePath());
        connection.open();
    }
}

void db::closeDatabase()
{
    return connection.close();
}
