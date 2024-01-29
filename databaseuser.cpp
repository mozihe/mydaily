#include "databaseuser.h"
#include <QDebug>
#include <QColor>
databaseuser::databaseuser()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString userDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(userDataPath);
    if (!dir.exists())
        dir.mkpath(".");
    db.setDatabaseName(userDataPath + "/UserData.db");
}

databaseuser::~databaseuser()
{
    db.close();
}

bool databaseuser::openDatabase()
{
    if (!db.open())
        return false;
    createTableIfNotExists();
    return true;
}

void databaseuser::createTableIfNotExists()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE, "
               "password TEXT, "
               "nickname TEXT DEFAULT '未设置昵称', "
               "avatar_path TEXT DEFAULT ':/images/head.png')");

    query.exec("CREATE TABLE IF NOT EXISTS events ("
               "event_id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "user_id INTEGER, "
               "event_name TEXT, "
               "event_date DATE, "
               "start_time TIME, "
               "end_time TIME, "
               "color TEXT,"
               "note TEXT,"
               "FOREIGN KEY(user_id) REFERENCES users(id))");
}

bool databaseuser::createUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    return query.exec();
}

bool databaseuser::validateUser(const QString &username, const QString &password)
{

    QSqlQuery checkUserQuery;
    checkUserQuery.prepare("SELECT password FROM users WHERE username = ?");
    checkUserQuery.addBindValue(username);
    checkUserQuery.exec();

    if (!checkUserQuery.next())
        return false;

    QString storedPassword = checkUserQuery.value(0).toString();
    return storedPassword == password;
}

bool databaseuser::isUsernameExist(const QString &username)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = ?");
    query.addBindValue(username);
    query.exec();
    return query.next();
}

QList<CalendarEvent> databaseuser::loadEvents(int userId) {
    QList<CalendarEvent> eventsList;
    QSqlQuery query;
    query.prepare("SELECT event_id, event_name, event_date, start_time, end_time, color FROM events WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);
    query.exec();

    while (query.next()) {
        CalendarEvent event;
        event.id = query.value(0).toInt();
        event.title = query.value(1).toString();
        event.date = query.value(2).toDate();
        event.start = query.value(3).toTime();
        event.end = query.value(4).toTime();
        QColor color(query.value(5).toString());
        event.color = color;

        eventsList.append(event);
    }

    return eventsList;
}
bool databaseuser::addEvent(int userId, const QString &eventName, const QDate &eventDate, const QTime &startTime, const QTime &endTime, int &eventId) {
    QSqlQuery query;
    query.prepare("INSERT INTO events (user_id, event_name, event_date, start_time, end_time, color) "
                  "VALUES (:user_id, :event_name, :event_date, :start_time, :end_time, :color)");
    query.bindValue(":user_id", userId);
    query.bindValue(":event_name", eventName);
    query.bindValue(":event_date", eventDate.toString("yyyy-MM-dd"));
    query.bindValue(":start_time", startTime.toString("HH:mm"));
    query.bindValue(":end_time", endTime.toString("HH:mm"));

    int r, g, b;
    do {
        r = QRandomGenerator::global()->bounded(256);
        g = QRandomGenerator::global()->bounded(256);
        b = QRandomGenerator::global()->bounded(256);
    } while (r + g + b > 600);

    QColor color(r, g, b);

    query.bindValue(":color", color.name());

    if (!query.exec())
        return false;

    eventId = query.lastInsertId().toInt();
    return true;
}
bool databaseuser::deleteEvent(int eventId) {
    QSqlQuery query;
    query.prepare("DELETE FROM events WHERE event_id = :event_id");
    query.bindValue(":event_id", eventId);
    return query.exec();
}

int databaseuser::getUserId(const QString& username)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username");
    query.bindValue(":username", username);
    query.exec();

    if (query.next())
    {
        int userId = query.value(0).toInt();
        return userId;
    }
    else
        return -1;
}

QPair<QString, QString> databaseuser::getUserDetails(int userId)
{
    QSqlQuery query;
    query.prepare("SELECT nickname, avatar_path FROM users WHERE id = :id");
    query.bindValue(":id", userId);
    query.exec();
    if (query.next())
    {
        QString nickname = query.value(0).toString();
        QString avatarPath = query.value(1).toString();
        return qMakePair(nickname, avatarPath);
    }

    return qMakePair(QString(), QString());
}

bool databaseuser::updateNickname(int userId, const QString &nickname)
{
    if (nickname.isEmpty()) {
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE users SET nickname = :nickname WHERE id = :id");
    query.bindValue(":nickname", nickname);
    query.bindValue(":id", userId);

    return query.exec();
}

bool databaseuser::updateAvatarPath(int userId, const QString &avatarPath)
{
    if (avatarPath.isEmpty()) {
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE users SET avatar_path = :avatarPath WHERE id = :id");
    query.bindValue(":avatarPath", avatarPath);
    query.bindValue(":id", userId);

    return query.exec();
}

bool databaseuser::isEventTimeConflict(int userId, const QDate &eventDate, const QTime &startTime, const QTime &endTime)
{
    QList<CalendarEvent> events = loadEvents(userId);
    for (const CalendarEvent &event : events)
    {
        if (event.date == eventDate)
        {
            if ((startTime < event.end && endTime > event.start) || (endTime > event.start && startTime < event.end))
            {
                return true;
            }
        }
    }
    return false;
}

bool databaseuser::saveEventNote(int eventId, const QString &note)
{
    QSqlQuery query;
    query.prepare("UPDATE events SET note = :note WHERE event_id = :event_id");
    query.bindValue(":note", note);
    query.bindValue(":event_id", eventId);

    if (!query.exec())
        return false;
    return true;
}

QString databaseuser::loadEventNote(int eventId)
{
    QSqlQuery query;
    query.prepare("SELECT note FROM events WHERE event_id = :event_id");
    query.bindValue(":event_id", eventId);

    if (query.exec())
    {
        if (query.next())
            return query.value(0).toString();
    }
    return QString();
}
