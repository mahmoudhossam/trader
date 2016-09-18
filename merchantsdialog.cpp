#include <QPushButton>
#include <QString>
#include "ui_merchantsdialog.h"
#include "merchantsdialog.h"
#include "util.h"
#include "db.h"

MerchantsDialog::MerchantsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MerchantsDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("إضافة");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("إلغاء");
    setFixedSize(size());
    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

MerchantsDialog::~MerchantsDialog()
{
    delete ui;
}

void MerchantsDialog::on_buttonBox_accepted()
{
    if(!ui->nameText->text().isEmpty())
    {
        // add new merchant
        QString name = ui->nameText->text();
        QString phone = ui->phoneText->text();
        QString address = ui->addressText->text();
        QString notes = ui->notesText->toPlainText();
        bool done = db::insertMerchant(name, address, phone, notes);
        if(done)
        {
            util::showMessage("تم إضافة العميل بنجاح");
            this->accept();
        } else {
            util::showMessage("خطأ فى البرنامج");
        }
    } else {
        util::showMessage("برجاء كتابة الإسم");
    }
}
