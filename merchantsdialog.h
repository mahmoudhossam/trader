#ifndef MERCHANTSDIALOG_H
#define MERCHANTSDIALOG_H

#include <QDialog>

namespace Ui {
class MerchantsDialog;
}

class MerchantsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MerchantsDialog(QWidget *parent = 0);
    ~MerchantsDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::MerchantsDialog *ui;
};

#endif // MERCHANTSDIALOG_H
