#include "weeklycalendarwidget.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QScrollArea>
#include <QDialog>
#include "databaseuser.h"
#include <QDateEdit>
WeekCalendarWidget::WeekCalendarWidget(int userid, QWidget *parent) : QWidget(parent)
{
    userId = userid;
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *container = new QWidget();
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
    gridLayout = new QGridLayout(container);



    yearLabel = new QLabel(QString::number(QDate::currentDate().year()) + "年", this);
    yearLabel->setStyleSheet("background: transparent;color: rgb(0, 0, 0);");
    gridLayout->addWidget(yearLabel, 0, 0, 1, 1, Qt::AlignLeft);

    for (int i = 0; i < 7; ++i)
    {
        dayLabels[i] = new QLabel(this);
        dayLabels[i]->setStyleSheet("background: transparent;color: rgb(0, 0, 0);");
        gridLayout->addWidget(dayLabels[i], 0, i + 1);
    }

    for (int i = 0; i <= 24 * RowsPerHour; ++i)
    {
        QString timeText = i < 24 * RowsPerHour ? QString("%1:%2").arg(i / RowsPerHour, 2, 10, QChar('0')).arg((i % RowsPerHour) * 60 / RowsPerHour, 2, 10, QChar('0')) : "24:00";
        QLabel *hourLabel = new QLabel(timeText, this);
        hourLabel->setStyleSheet("background: transparent;color: rgb(0, 0, 0);");
        gridLayout->addWidget(hourLabel, i + 1, 0);
    }

    for (int i = 0; i <= 24 * RowsPerHour; ++i)
    {
        gridLayout->setRowMinimumHeight(i, 20);
    }

    container->setLayout(gridLayout);

    QHBoxLayout *navigationLayout = new QHBoxLayout();
    QPushButton *previousWeekButton = new QPushButton("<");
    previousWeekButton->setStyleSheet("background-color: rgb(200, 140, 210);");
    connect(previousWeekButton, &QPushButton::clicked, this, &WeekCalendarWidget::goToPreviousWeek);

    QDateEdit *jumpToDateEdit = new QDateEdit();
    jumpToDateEdit->setDisplayFormat("yyyy-MM-dd");
    jumpToDateEdit->setCalendarPopup(true);
    jumpToDateEdit->setDate(QDate::currentDate());

    QPushButton *jumpButton = new QPushButton("跳转");
    jumpButton->setStyleSheet("background-color: rgb(200, 140, 210);");
    connect(jumpButton, &QPushButton::clicked, this, [=](){
        QDate date = jumpToDateEdit->date();
        if(date.isValid())
            jumpToDate(date);
    });

    QPushButton *nextWeekButton = new QPushButton(">");
    nextWeekButton->setStyleSheet("background-color: rgb(200, 140, 210);");
    connect(nextWeekButton, &QPushButton::clicked, this, &WeekCalendarWidget::goToNextWeek);

    navigationLayout->addWidget(previousWeekButton);
    navigationLayout->addWidget(jumpToDateEdit, 1);
    navigationLayout->addWidget(jumpButton);
    navigationLayout->addWidget(nextWeekButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    scrollArea->setStyleSheet("background-color: rgba(255, 255, 255, 100);");
    mainLayout->addWidget(scrollArea);
    mainLayout->addLayout(navigationLayout);

    setWeek(QDate::currentDate());
}

WeekCalendarWidget::~WeekCalendarWidget()
{
    clearWeek();
}

void WeekCalendarWidget::addEvent(const QDate &date, const QTime &startTime, const QTime &endTime, const QColor &color, const QString &title, const int eventId)
{
    QPushButton *button = new QPushButton(title, this);
    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    button->setStyleSheet(QString("color: rgb(255, 255, 255);background-color: %1").arg(color.name()));

    int startRow = timeToRow(startTime);
    int duration = calculateDurationInRows(startTime, endTime);
    gridLayout->addWidget(button, startRow, date.dayOfWeek(), duration, 1);

    connect(button, &QPushButton::clicked, this, [this, eventId]() {
        this->editEventNote(eventId);
    });
    eventButtons.insert({date, startTime}, button);
}

void WeekCalendarWidget::setWeek(const QDate &date)
{
    currentDate = date;
    QDate startDate = currentDate.addDays(-currentDate.dayOfWeek() + 1);
    yearLabel->setText(QString::number(currentDate.year()) + "年");

    for (int i = 0; i < 7; ++i) {
        QDate dayDate = startDate.addDays(i);
        dayLabels[i]->setText(dayDate.toString("MMM d ddd"));
    }
    updateWeek();
}


void WeekCalendarWidget::updateWeek()
{
    clearWeek();

    databaseuser dbUser;
    if (!dbUser.openDatabase())
        return;

    QList<CalendarEvent> events = dbUser.loadEvents(userId);

    QDate startDate = currentDate.addDays(-currentDate.dayOfWeek() + 1);
    QDate endDate = startDate.addDays(7);

    for (const CalendarEvent &event : events) {
        if (event.date >= startDate && event.date < endDate) {
            addEvent(event.date, event.start, event.end, event.color, event.title, event.id);
        }
    }
}

void WeekCalendarWidget::clearWeek()
{
    qDeleteAll(eventButtons);
    eventButtons.clear();
}

int WeekCalendarWidget::timeToRow(const QTime &time) const
{
    return (time.hour() * RowsPerHour) + (time.minute() / 10) + 1;
}

int WeekCalendarWidget::calculateDurationInRows(const QTime &startTime, const QTime &endTime) const
{
    return timeToRow(endTime) - timeToRow(startTime);
}

void WeekCalendarWidget::goToNextWeek()
{
    setWeek(currentDate.addDays(7));
}

void WeekCalendarWidget::goToPreviousWeek()
{
    setWeek(currentDate.addDays(-7));
}

void WeekCalendarWidget::jumpToDate(const QDate &date)
{
    setWeek(date);
}

void WeekCalendarWidget::getId(int Id)
{
    userId = Id;
}

void WeekCalendarWidget::editEventNote(int eventId)
{
    databaseuser dbUser;
    if (!dbUser.openDatabase())
        return;

    QString note = dbUser.loadEventNote(eventId);

    QDialog dialog(this);
    QVBoxLayout layout(&dialog);
    QTextEdit textEdit;
    textEdit.setText(note);
    layout.addWidget(&textEdit);
    QPushButton saveButton("保存", &dialog);
    layout.addWidget(&saveButton);
    dialog.setFixedSize(300, 300);
    dialog.setWindowTitle("备注");

    connect(&saveButton, &QPushButton::clicked, [eventId, &textEdit, &dialog]()
    {
        databaseuser dbUser;
        if (dbUser.openDatabase())
            dbUser.saveEventNote(eventId, textEdit.toPlainText());
        dialog.close();
    });

    dialog.exec();
}
