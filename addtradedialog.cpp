#include <QPushButton>
#include <QDateTime>
#include "addtradedialog.h"
#include "ui_addtradedialog.h"
#include "db.h"
#include "util.h"
#include "mainwindow.h"
#include "merchantdetaildialog.h"

QString name;
int id;

AddTradeDialog::AddTradeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTradeDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("إضافة");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("إلغاء");
    ui->goodsRadio->setChecked(true);
    setFixedSize(size());
    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

AddTradeDialog::~AddTradeDialog()
{
    delete ui;
}

void AddTradeDialog::showDialog(int merchant_id, QString merchant_name)
{
    name = merchant_name;
    id = merchant_id;
    ui->nameText->setText(merchant_name);
    exec();
}

void AddTradeDialog::setTotal()
{
    QString box_count = ui->boxesText->text();
    QString kilos = ui->kilosText->text();
    QString price_kilo = ui->priceText->text();

    if(ui->goodsRadio->isChecked() && !box_count.isEmpty()
        && !kilos.isEmpty() && !price_kilo.isEmpty())
    {
        double total = (box_count.toDouble() * 3) + (price_kilo.toDouble() * kilos.toDouble());
        ui->totalText->setText(QString::number(total));
    }
}

void AddTradeDialog::on_goodsRadio_toggled(bool checked)
{
       ui->boxesText->setEnabled(checked);
       ui->kilosText->setEnabled(checked);
       ui->priceText->setEnabled(checked);
       ui->productText->setEnabled(checked);
       ui->totalText->setEnabled(!checked);
       ui->boxesText->clear();
       ui->kilosText->clear();
       ui->priceText->clear();
       ui->productText->clear();
       ui->totalText->clear();
}

void AddTradeDialog::on_buttonBox_accepted()
{
    QString box_count = ui->boxesText->text();
    QString kilos = ui->kilosText->text();
    QString price_kilo = ui->priceText->text();
    QString product = ui->productText->text();
    QString total = ui->totalText->text();
    QString date = QDateTime::currentDateTime().toString("yyyy/M/d hh:mm AP");
    bool done = db::newTrade(id, box_count, kilos, price_kilo, product, total, date);
    if(done)
    {
        util::showMessage("تم إضافة المعاملة بنجاح");
        MainWindow* mw = qobject_cast<MainWindow *>(this->parent()->parent()->parent());
        mw->initializeTableView();
        MerchantDetailDialog* md = qobject_cast<MerchantDetailDialog *>(this->parent());
        md->updateTable(id);
    } else
    {
        util::showMessage("خطأ. لم يتم إضافة المعاملة");
    }
}

void AddTradeDialog::on_buttonBox_rejected()
{
    this->close();
}

void AddTradeDialog::on_boxesText_textChanged()
{
    setTotal();
}

void AddTradeDialog::on_kilosText_textChanged()
{
    setTotal();
}

void AddTradeDialog::on_priceText_textChanged()
{
    setTotal();
}
