#include "merchantsdialog.h"
#include "ui_merchantsdialog.h"
#include <QPushButton>
#include <util.h>
#include <QString>
#include <db.h>

MerchantsDialog::MerchantsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MerchantsDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("إضافة");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("إلغاء");
}

MerchantsDialog::~MerchantsDialog()
{
    delete ui;
}

void MerchantsDialog::on_buttonBox_accepted()
{
    db DB();
    // add new merchant
    QString name = ui->nameText->text();
    QString phone = ui->phoneText->text();
    QString address = ui->addressText->text();
    QString notes = ui->notesText->toPlainText();
    bool done = db::insertMerchant(name, address, phone, notes);
    if(done)
    {
        util::showMessage("تم إضافة المورد بنجاح");
    } else {
        util::showMessage("خطأ فى البرنامج");
    }
}
