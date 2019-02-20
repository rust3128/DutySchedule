#include "database.h"
#include "LoggingCategories/loggingcategories.h"

#include <QFile>
#include <QMessageBox>
#include <QSettings>
#include <QSqlQuery>

#define SETTINGS_FILE_NAME  "DutySchedule.ini"


DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

bool DataBase::openDataBase()
{
    QFile iniFile(SETTINGS_FILE_NAME);
    if(!iniFile.exists()){
        qCritical(logCritical()) << this->tr("Отсутсвует файл настроек приложения");
        QMessageBox::critical(nullptr,this->tr("Ошибка"),this->tr("Отсутсвует файл настроки приложения.\nСоединение с базой данных не установлено."));
        connectDlg = new ConnectionDialog();
        connectDlg->exec();
        connectDlg->deleteLater();
//        return false;
    }
    QSettings settings(SETTINGS_FILE_NAME, QSettings::IniFormat);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    settings.beginGroup("DATABASE");
    db.setHostName(settings.value("HostName").toString());
    db.setDatabaseName(settings.value("DataBase").toString());
    db.setUserName(settings.value("User").toString());
    db.setPassword(settings.value("Password").toString());
    settings.endGroup();

    if(!db.open()) {
        qCritical(logCritical()) <<  "Не возможно подключиться к базе данных." << endl << "Причина:" << db.lastError().text();
        QMessageBox::critical(nullptr, QObject::tr("Не могу открыть базу данных"),
                              QString("Не могу установить соединение с базой данных\nПричина: %1\n Проверьте настройки подключения.").arg(db.lastError().text()),
                              QMessageBox::Cancel);
        connectDlg = new ConnectionDialog();
        connectDlg->exec();
        connectDlg->deleteLater();
        return false;
    }
    QSqlQuery q;
    if(!q.exec("SET lc_time_names = ru_RU")) qInfo(logInfo()) << q.lastError().text();
    return true;
}


