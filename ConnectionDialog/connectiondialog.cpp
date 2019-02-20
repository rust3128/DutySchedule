#include "connectiondialog.h"
#include "ui_connectiondialog.h"

#define SETTINGS_FILE_NAME  "DutySchedule.ini"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);



    readConnData();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::readConnData()
{
    QSettings settings(SETTINGS_FILE_NAME,QSettings::IniFormat);
    settings.beginGroup("DATABASE");
    ui->LineEditServer->setText(settings.value("HostName").toString());
    ui->LineEditDataBase->setText(settings.value("DataBase").toString());
    ui->LineEditUser->setText(settings.value("User").toString());
    ui->LineEditPassword->setText(settings.value("Password").toString());
    settings.endGroup();
    settings.destroyed();
}

void ConnectionDialog::on_pushButtonSave_clicked()
{
    QSettings settings(SETTINGS_FILE_NAME,QSettings::IniFormat);
    settings.beginGroup("DATABASE");
    settings.setValue("HostName", ui->LineEditServer->text().trimmed());
    settings.setValue("DataBase", ui->LineEditDataBase->text().trimmed());
    settings.setValue("User", ui->LineEditUser->text().trimmed());
    settings.setValue("Password",ui->LineEditPassword->text().trimmed());
    settings.endGroup();

    this->accept();
}
