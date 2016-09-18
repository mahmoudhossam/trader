#ifndef ADDTRADEDIALOG_H
#define ADDTRADEDIALOG_H

#include <QDialog>

namespace Ui {
class AddTradeDialog;
}

class AddTradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTradeDialog(QWidget *parent = 0);
    ~AddTradeDialog();
    void setTotal();
    void showDialog(int merchant_id, QString merchant_name);

private slots:
    void on_goodsRadio_toggled(bool checked);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_boxesText_textChanged();

    void on_kilosText_textChanged();

    void on_priceText_textChanged();

private:
    Ui::AddTradeDialog *ui;
};

#endif // ADDTRADEDIALOG_H
