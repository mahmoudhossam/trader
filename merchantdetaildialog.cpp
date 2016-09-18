#include <QSqlRecord>
#include "merchantdetaildialog.h"
#include "ui_merchantdetaildialog.h"
#include "addtradedialog.h"
#include "db.h"

QSqlRecord merchant;

MerchantDetailDialog::MerchantDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MerchantDetailDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

MerchantDetailDialog::~MerchantDetailDialog()
{
    delete ui;
}

void MerchantDetailDialog::showMerchant(long long id)
{
    this->updateTable(id);
    this->exec();
}

void MerchantDetailDialog::updateTable(long long id)
{
    merchant = db::getMerchant(id)->record(0);
    ui->nameText->setText(merchant.value("merchant_name").toString());
    ui->phoneText->setText(merchant.value("phone").toString());
    ui->addressText->setText(merchant.value("address").toString());
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(db::getMerchantTrades(id));
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->resizeColumnsToContents();
}

void MerchantDetailDialog::on_pushButton_clicked()
{
    AddTradeDialog dialog(this);
    dialog.showDialog(merchant.value("id").toInt(), merchant.value("merchant_name").toString());
}
