#ifndef DATABASEUSER_H
#define DATABASEUSER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>
#include <QDate>
#include <QTime>
#include "weeklycalendarwidget.h"

class databaseuser
{
public:

    databaseuser();
    ~databaseuser();
    bool openDatabase();
    bool createUser(const QString &username, const QString &password);
    bool validateUser(const QString &username, const QString &password);
    bool isUsernameExist(const QString &username);
    QList<CalendarEvent> loadEvents(int userId);
    bool addEvent(int userId, const QString &eventName, const QDate &eventDate, const QTime &startTime, const QTime &endTime, int &eventId);
    bool deleteEvent(int eventId);
    int getUserId(const QString& username);
    QPair<QString, QString> getUserDetails(int userId);
    bool updateNickname(int userId, const QString &nickname);
    bool updateAvatarPath(int userId, const QString &avatarPath);
    bool isEventTimeConflict(int userId, const QDate &eventDate, const QTime &startTime, const QTime &endTime);
    bool saveEventNote(int eventId, const QString &note);
    QString loadEventNote(int eventId);

private:
    QSqlDatabase db;
    void createTableIfNotExists();
};

#endif // DATABASEUSER_H
