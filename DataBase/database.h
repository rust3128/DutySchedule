#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

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

private:
    QString hostName() const;
    void setHostName(const QString &hostName);
    QString dataBaseName() const;
    void setDataBaseName(const QString &dataBaseName);
    QString userDatabase() const;
    void setUserDatabase(const QString &userDatabase);
    QString password() const;
    void setPassword(const QString &password);

};

#endif // DATABASE_H
