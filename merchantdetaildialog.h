#ifndef MERCHANTDETAILDIALOG_H
#define MERCHANTDETAILDIALOG_H

#include <QDialog>

namespace Ui {
class MerchantDetailDialog;
}

class MerchantDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MerchantDetailDialog(QWidget *parent = 0);
    ~MerchantDetailDialog();
    void showMerchant(long long id);
    void updateTable(long long id);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MerchantDetailDialog *ui;
};

#endif // MERCHANTDETAILDIALOG_H
