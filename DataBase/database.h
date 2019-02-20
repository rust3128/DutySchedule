#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include "ConnectionDialog/connectiondialog.h"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    bool openDataBase();

signals:

public slots:

private:
    QSqlDatabase db;
    ConnectionDialog *connectDlg;
private:


};

#endif // DATABASE_H
