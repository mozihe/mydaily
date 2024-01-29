#ifndef CALENDARAPP_H
#define CALENDARAPP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <QComboBox>
#include <QFrame>
#include <QTime>
#include <QDateEdit>
#include <QStackedLayout>
#include <QPainterPath>
#include <QList>
#include <QSystemTrayIcon>

#include "weeklycalendarwidget.h"
#include "usersettingwindow.h"
#include "databaseuser.h"


class CircleButton : public QPushButton {
    Q_OBJECT
public:
    CircleButton(QWidget *parent = nullptr) : QPushButton(parent)
    {
        setFixedSize(100, 100);
    }
    void setAvatar(const QString &avatarPath)
    {
        avatarPixmap = QPixmap(avatarPath);
        update();
    }
    void getId(int userId)
    {
        this->userId = userId;
    }
protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing, true);
        QPixmap circlePixmap = avatarPixmap.scaled(width(), height(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        QPainterPath path;
        path.addEllipse(0, 0, width(), height());
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, circlePixmap);
    }
    void mousePressEvent (QMouseEvent *event) override
    {
        UserSettingsWindow settingsWindow(userId);
        connect(&settingsWindow, &UserSettingsWindow::userDetailsUpdated, this, &CircleButton::userDetailsUpdated);
        settingsWindow.exec();
        QPushButton::mousePressEvent(event);
    }
private:
    QPixmap avatarPixmap;
    int userId;
signals:
    void userDetailsUpdated();
};


class CalendarApp : public QWidget {
    Q_OBJECT

public:
    explicit CalendarApp(QWidget *parent = nullptr);


private slots:
    void addEvent();
    void updateDateTimeChoices();
    void updateDayChoices(int year, int month);
    void fillDateChoices();
    void fillTimeChoices();
    void toggleLayouts();
    void deleteEvent();
    void loadEvents();
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void setupTrayIcon();


public slots:
    void onUserLoggedIn(int userId){userid = userId;loadEvents();refreshUserDetails();setupTrayIcon();setupEventReminders();this->show();}
    void refreshUserDetails();
    void setupEventReminders();

protected:
    void closeEvent(QCloseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    CircleButton *userHead;
    QStackedLayout *stackedLayout;
    QComboBox *yearEdit;
    QComboBox *monthEdit;
    QComboBox *dayEdit;
    QLineEdit *eventNameEdit;
    QComboBox *startTimeEdit, *endTimeEdit;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *addDailyButton;
    QPushButton *confirmButton;
    QVBoxLayout *eventsLayout;
    QVBoxLayout *dailyLayout;
    WeekCalendarWidget *calendarWidget;
    QLabel *infoLabel;
    QLabel *username;
    QSystemTrayIcon *trayIcon;
    int userid;
    RandomImageWidget *riw;
    RandomGreetingsWidget *rgw;

    QScrollArea* createEventsScrollArea();
    QFrame* createInputArea();
    QList<QTimer*> reminderTimers;
    void createEventCard(const QString &name, const QDate &date, const QTime &startTime, const QTime &endTime, int eventId);


};

#endif // CALENDARAPP_H
