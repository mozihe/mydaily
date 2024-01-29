#include "calendarapp.h"
#include "weeklycalendarwidget.h"
#include "databaseuser.h"
#include <QDateTime>
#include <QFrame>
#include <QScrollArea>
#include <QGridLayout>
#include <QSizePolicy>
#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QCloseEvent>
#include <QDebug>
#include "datetimewidget.h"

CalendarApp::CalendarApp(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1600, 900);

    setStyleSheet("CalendarApp { background-image: url(:/background/background2.jpeg); }");

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    calendarWidget = new WeekCalendarWidget(userid ,this);
    mainLayout->addWidget(calendarWidget, 7);

    stackedLayout = new QStackedLayout();
    QWidget *layout1Widget = new QWidget();
    QWidget *layout2Widget = new QWidget();

    QVBoxLayout *rightLayout1 = new QVBoxLayout();
    QVBoxLayout *rightLayout2 = new QVBoxLayout();

    rightLayout1 = new QVBoxLayout(layout1Widget);
    rightLayout2 = new QVBoxLayout(layout2Widget);

    userHead = new CircleButton(this);
    rightLayout2->addWidget(userHead, 0, Qt::AlignHCenter);
    connect(userHead, &CircleButton::userDetailsUpdated,
            this, &CalendarApp::refreshUserDetails);

    username = new QLabel();
    username->setStyleSheet("color: rgb(255, 255, 255);");
    username->setText("昵称未设置");

    rightLayout2->addWidget(username, 0, Qt::AlignHCenter);

    QWidget *tryi = new QWidget();
    QWidget *trye = new QWidget();

    tryi = createTextDisplayWidget();
    trye = createAnalogClockWidget();

    rightLayout2->addWidget(tryi);
    rightLayout2->addWidget(trye);

    QScrollArea *scrollArea1 = createEventsScrollArea();

    confirmButton = new QPushButton("完成", this);
    confirmButton->setStyleSheet("background-color: rgb(255, 105, 180);color: rgb(255, 255, 255);");
    connect(confirmButton, &QPushButton::clicked, this, &CalendarApp::toggleLayouts);
    connect(confirmButton, &QPushButton::clicked, calendarWidget, &WeekCalendarWidget::updateWeek);
    connect(confirmButton, &QPushButton::clicked, this, &CalendarApp::setupEventReminders);

    editButton = new QPushButton("编辑", this);
    editButton->setStyleSheet("background-color: rgb(255, 105, 180);color: rgb(255, 255, 255);");
    connect(editButton, &QPushButton::clicked, this, &CalendarApp::toggleLayouts);
    rgw = new RandomGreetingsWidget();
    rightLayout2->addWidget(rgw, 0, Qt::AlignHCenter);

    riw = new RandomImageWidget();

    rightLayout1->addWidget(scrollArea1);
    rightLayout2->addWidget(riw, 0, Qt::AlignHCenter);

    //connect(confirmButton, &QPushButton::clicked, riw, &RandomImageWidget::updateImage);
    //connect(confirmButton, &QPushButton::clicked, rgw, &RandomGreetingsWidget::updateGreeting);


    QFrame *inputFrame = createInputArea();
    rightLayout1->addWidget(inputFrame);

    rightLayout1->addWidget(confirmButton);
    rightLayout2->addWidget(editButton);

    stackedLayout->addWidget(layout2Widget);
    stackedLayout->addWidget(layout1Widget);

    mainLayout->addLayout(stackedLayout, 1);
}

void CalendarApp::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap(":/background/background2.jpeg");
    painter.drawPixmap(rect(), pixmap);
}

QScrollArea* CalendarApp::createEventsScrollArea()
{
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setStyleSheet("background-color: rgba(255, 255, 255, 100);");
    QWidget *eventsContainer = new QWidget();
    eventsLayout = new QVBoxLayout(eventsContainer);
    eventsLayout->setAlignment(Qt::AlignTop);
    scrollArea->setWidget(eventsContainer);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    return scrollArea;
}

QFrame* CalendarApp::createInputArea()
{
    QFrame *inputFrame = new QFrame();
    inputFrame->setFrameShape(QFrame::StyledPanel);
    inputFrame->setFrameShadow(QFrame::Raised);

    QVBoxLayout *inputLayout = new QVBoxLayout(inputFrame);



    eventNameEdit = new QLineEdit();
    eventNameEdit->setPlaceholderText("请输入事件名称");
    eventNameEdit->setStyleSheet("background: transparent;border: 2px solid #000000;color: rgb(0, 0, 0);");
    eventNameEdit->setMaxLength(12);
    inputLayout->addWidget(eventNameEdit);

    yearEdit = new QComboBox(this);
    yearEdit->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    monthEdit = new QComboBox(this);
    monthEdit->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    dayEdit = new QComboBox(this);
    dayEdit->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    fillDateChoices();

    connect(yearEdit, &QComboBox::currentTextChanged, this, [this]() {updateDayChoices(yearEdit->currentText().toInt(), monthEdit->currentText().toInt());});
    connect(monthEdit, &QComboBox::currentTextChanged, this, [this]() {updateDayChoices(yearEdit->currentText().toInt(), monthEdit->currentText().toInt());});

    QHBoxLayout *dateLayout = new QHBoxLayout();
    dateLayout->addWidget(yearEdit);
    dateLayout->addWidget(monthEdit);
    dateLayout->addWidget(dayEdit);
    inputLayout->addLayout(dateLayout);

    QHBoxLayout *timeLayout = new QHBoxLayout();
    startTimeEdit = new QComboBox(this);
    endTimeEdit = new QComboBox(this);
    startTimeEdit->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    endTimeEdit->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    fillTimeChoices();
    connect(startTimeEdit, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CalendarApp::updateDateTimeChoices);

    timeLayout->addWidget(startTimeEdit, 1);
    timeLayout->addWidget(endTimeEdit, 1);

    inputLayout->addLayout(timeLayout);

    addButton = new QPushButton("添加事件", this);
    addButton->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    connect(addButton, &QPushButton::clicked, this, &CalendarApp::addEvent);
    inputLayout->addWidget(addButton);

    infoLabel = new QLabel();
    infoLabel->setStyleSheet("background: transparent;color: rgb(0, 0, 0);");
    infoLabel->setText("");
    inputLayout->addWidget(infoLabel);

    inputFrame->setStyleSheet("background-color: rgba(255, 255, 255, 100);color: rgb(255, 255, 255);");

    return inputFrame;
}

void CalendarApp::addEvent()
{
    QString eventName = eventNameEdit->text();
    if (eventName.isEmpty())
    {
        infoLabel->setText("事件名不能为空");
        return;
    }

    int year = yearEdit->currentText().toInt();
    int month = monthEdit->currentText().toInt();
    int day = dayEdit->currentText().toInt();
    QDate eventDate(year, month, day);
    QTime startTime = QTime::fromString(startTimeEdit->currentText(), "HH:mm");
    QTime endTime = QTime::fromString(endTimeEdit->currentText(), "HH:mm");

    databaseuser dbUser;
    if (!dbUser.openDatabase())
    {
        infoLabel->setText("数据库错误");
        return;
    }
    if (dbUser.isEventTimeConflict(userid, eventDate, startTime, endTime))
    {
        infoLabel->setText("时间重叠了");
        return;
    }

    int eventId;
    if (!dbUser.addEvent(userid, eventName, eventDate, startTime, endTime, eventId))
    {
        infoLabel->setText("添加失败");
        return;
    }

    createEventCard(eventName, eventDate, startTime, endTime, eventId);
    infoLabel->setText("添加成功");
}

void CalendarApp::createEventCard(const QString &name, const QDate &date, const QTime &startTime, const QTime &endTime, int eventId)
{
    QFrame *eventCard = new QFrame();
    eventCard->setFrameShape(QFrame::StyledPanel);
    eventCard->setFrameShadow(QFrame::Raised);
    eventCard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    eventCard->setFixedHeight(140);

    QVBoxLayout *cardLayout = new QVBoxLayout(eventCard);
    QLabel *nameLabel = new QLabel(name);
    QLabel *dateLabel = new QLabel(date.toString("yyyy-MM-dd"));
    QLabel *timeLabel = new QLabel(startTime.toString("HH:mm") + " - " + endTime.toString("HH:mm"));

    QPushButton *deleteButton = new QPushButton("删除", eventCard);
    deleteButton->setProperty("eventId", eventId);
    deleteButton->setStyleSheet("background-color: rgb(255, 105, 180);color: rgb(255, 255, 255);");
    connect(deleteButton, &QPushButton::clicked, this, &CalendarApp::deleteEvent);

    cardLayout->addWidget(nameLabel);
    cardLayout->addWidget(dateLabel);
    cardLayout->addWidget(timeLabel);
    cardLayout->addWidget(deleteButton);

    eventCard->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");

    eventsLayout->addWidget(eventCard);
}

void CalendarApp::fillTimeChoices()
{
    startTimeEdit->clear();
    endTimeEdit->clear();
    for (int hour = 0; hour < 24; ++hour)
    {
        for (int minute = 0; minute < 60; minute += 10)
        {
            QString timeText = QTime(hour, minute).toString("hh:mm");
            startTimeEdit->addItem(timeText);
            if (hour == 23 && minute == 40)
                break;
        }
    }
    for (int hour = 0; hour < 24; ++hour)
    {
        for (int minute = 0; minute < 60; minute += 10)
        {
            QString timeText = QTime(hour, minute).toString("hh:mm");
            endTimeEdit->addItem(timeText);
        }
    }
    updateDateTimeChoices();
}

void CalendarApp::fillDateChoices()
{
    yearEdit->clear();
    monthEdit->clear();
    dayEdit->clear();

    QDate currentDate = QDate::currentDate();
    int currentYear = currentDate.year();
    int currentMonth = currentDate.month();
    int currentDay = currentDate.day();

    for (int year = 2000; year <= 3000; ++year)
    {
        yearEdit->addItem(QString::number(year), year);
        if (year == currentYear)
            yearEdit->setCurrentIndex(yearEdit->count() - 1);
    }

    for (int month = 1; month <= 12; ++month)
    {
        monthEdit->addItem(QString::number(month), month);
        if (month == currentMonth)
            monthEdit->setCurrentIndex(month - 1);
    }

    updateDayChoices(currentYear, currentMonth);

    dayEdit->setCurrentIndex(currentDay - 1);
}

void CalendarApp::updateDateTimeChoices()
{
    int startTimeIndex = startTimeEdit->currentIndex();
    endTimeEdit->clear();

    for (int i = startTimeIndex + 1; i < startTimeEdit->count(); ++i)
        endTimeEdit->addItem(startTimeEdit->itemText(i));
}

void CalendarApp::updateDayChoices(int year, int month)
{
    dayEdit->clear();
    QDate date(year, month, 1);
    int daysInMonth = date.daysInMonth();

    for (int day = 1; day <= daysInMonth; ++day)
        dayEdit->addItem(QString::number(day));
}

void CalendarApp::toggleLayouts()
{
    int currentIndex = stackedLayout->currentIndex();
    int nextIndex = (currentIndex + 1) % stackedLayout->count();
    stackedLayout->setCurrentIndex(nextIndex);
}

void CalendarApp::deleteEvent()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;

    int eventId = button->property("eventId").toInt();

    databaseuser dbUser;
    if (!dbUser.openDatabase())
        return;

    dbUser.deleteEvent(eventId);

    QFrame *eventCard = qobject_cast<QFrame *>(button->parent());
    if (eventCard)
        eventCard->deleteLater();
}

void CalendarApp::loadEvents()
{
    databaseuser dbUser;
    if (!dbUser.openDatabase())
        return;

    calendarWidget->getId(userid);

    QList<CalendarEvent> events = dbUser.loadEvents(userid);

    for (const CalendarEvent &event : events)
        createEventCard(event.title, event.date, event.start, event.end, event.id);
}

void CalendarApp::refreshUserDetails()
{
    databaseuser dbUser;
    if (!dbUser.openDatabase())
        return;
    auto userDetails = dbUser.getUserDetails(userid);
    QString nickname = userDetails.first;
    QString avatarPath = userDetails.second;
    userHead->getId(userid);

    username->setText(nickname);
    userHead->setAvatar(avatarPath);
}

void CalendarApp::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible())
    {
        hide();
        event->ignore();
    }
    else
        event->accept();
}


void CalendarApp::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger)
    {
        showNormal();
        setWindowState((windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
        activateWindow();
    }
}

void CalendarApp::setupTrayIcon()
{
    calendarWidget->updateWeek();
    trayIcon = new QSystemTrayIcon(this);

    trayIcon->setIcon(QIcon(":/background/logal.jpg"));
    QMenu *trayIconMenu = new QMenu(this);
    QAction *quitAction = trayIconMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    QAction *showAction = trayIconMenu->addAction("显示");
    connect(showAction, &QAction::triggered, this, &CalendarApp::showNormal);

    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();

    connect(trayIcon, &QSystemTrayIcon::activated, this, &CalendarApp::onTrayIconActivated);
}

void CalendarApp::setupEventReminders()
{
    qDeleteAll(reminderTimers);
    reminderTimers.clear();
    databaseuser dbUser;
    if (!dbUser.openDatabase())
        return;

    QList<CalendarEvent> events = dbUser.loadEvents(userid);

    for (const CalendarEvent &event : events)
    {
        QDateTime reminderTime = QDateTime(event.date, event.start).addSecs(-20 * 60);

        QDateTime currentTime = QDateTime::currentDateTime();

        if (currentTime < reminderTime) {
            QTimer *timer = new QTimer(this);
            reminderTimers.append(timer);
            timer->setSingleShot(true);
            connect(timer, &QTimer::timeout, [event, this]() {trayIcon->showMessage("提醒", "20分钟后即将开始的事件: " + event.title);});

            int msToReminder = currentTime.msecsTo(reminderTime);
            timer->start(msToReminder);
        }
    }
}
