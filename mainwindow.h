#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DataBase/database.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void show();

private:
    Ui::MainWindow *ui;
    DataBase *db;
};

#endif // MAINWINDOW_H
