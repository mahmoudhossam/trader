#include "db.h"
#include <QString>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>


QSqlDatabase db::connection;

QSqlQueryModel* db::getMerchantsModel()
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

QSqlQueryModel* db::getMerchantsNameModel()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query_text = "select merchant_name FROM merchants";
    QSqlQuery query(query_text, connection);
    model->setQuery(query);
    return model;
}

void db::openDatabase()
{
    QDir path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
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
