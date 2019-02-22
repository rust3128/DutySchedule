#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "WorkTypeDialog/worktypedialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show()
{
    QMainWindow::show();

}

void MainWindow::on_actionWorkType_triggered()
{
    WorkTypeDialog *workTypeDlg = new WorkTypeDialog();
    workTypeDlg->exec();
}
