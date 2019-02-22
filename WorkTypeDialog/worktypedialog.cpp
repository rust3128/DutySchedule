#include "worktypedialog.h"
#include "ui_worktypedialog.h"

WorkTypeDialog::WorkTypeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkTypeDialog)
{
    ui->setupUi(this);
}

WorkTypeDialog::~WorkTypeDialog()
{
    delete ui;
}
