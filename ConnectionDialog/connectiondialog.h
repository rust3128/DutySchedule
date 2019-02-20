#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();
    void readConnData();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::ConnectionDialog *ui;

};

#endif // CONNECTIONDIALOG_H
