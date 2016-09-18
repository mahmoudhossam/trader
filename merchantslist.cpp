#include <QSortFilterProxyModel>
#include "merchantslist.h"
#include "merchantdetaildialog.h"
#include "ui_merchantslist.h"
#include "db.h"

QSortFilterProxyModel* proxy;

Merchantslist::Merchantslist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Merchantslist)
{
    ui->setupUi(this);
    initializeList();
    setFixedSize(size());
    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

Merchantslist::~Merchantslist()
{
    delete ui;
}

void Merchantslist::initializeList()
{
    proxy = new QSortFilterProxyModel;
    proxy->setSourceModel(db::getMerchantsModel());
    proxy->setFilterKeyColumn(-1);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(proxy);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->resizeColumnsToContents();
}


void Merchantslist::on_lineEdit_returnPressed()
{
    ui->pushButton->click();
}

void Merchantslist::on_pushButton_clicked()
{
    proxy->setFilterFixedString(ui->lineEdit->text());
}

void Merchantslist::on_tableView_doubleClicked(const QModelIndex &index)
{
    long long id = index.model()->sibling(index.row(), 0, index).data().toLongLong();
    MerchantDetailDialog dialog(this);
    dialog.showMerchant(id);
}
