#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_SearchButton_clicked();

private:
    Ui::MainWindow *ui;
    void initializeTableView();
    void setupCompleter();
};

#endif // MAINWINDOW_H
