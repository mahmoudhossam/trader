#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"
#include "db.h"
#include "merchantsdialog.h"
#include "merchantslist.h"
#include "addtradedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db::openDatabase();
    this->initializeTableView();
    this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
    db::closeDatabase();
}

void MainWindow::initializeTableView()
{
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(db::getTradesModel());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_pushButton_clicked()
{
    Merchantslist list(this);
    list.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    MerchantsDialog dialog(this);
    dialog.exec();
}
