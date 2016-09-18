#ifndef MERCHANTSLIST_H
#define MERCHANTSLIST_H

#include <QDialog>

namespace Ui {
class Merchantslist;
}

class Merchantslist : public QDialog
{
    Q_OBJECT

public:
    explicit Merchantslist(QWidget *parent = 0);
    ~Merchantslist();

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::Merchantslist *ui;
    void initializeList();
};

#endif // MERCHANTSLIST_H
