#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <util.h>
#include <db.h>
#include <merchantsdialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db::openDatabase();
    this->initializeTableView();
    setupCompleter();
}

MainWindow::~MainWindow()
{
    delete ui;
    db::closeDatabase();
}

void MainWindow::initializeTableView()
{
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(db::getMerchantsModel());
}

void MainWindow::on_action_triggered()
{
    MerchantsDialog dialog;
    dialog.exec();
}

void MainWindow::on_SearchButton_clicked()
{
    util::showMessage("Clicked!");
}

void MainWindow::setupCompleter()
{
    QCompleter *completer = new QCompleter(db::getMerchantsNameModel(), this);
    completer->setCompletionColumn(0);
    ui->merchantSearch->setCompleter(completer);
}
