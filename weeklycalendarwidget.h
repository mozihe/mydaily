#ifndef WEEKLYCALENDARWIDGET_H
#define WEEKLYCALENDARWIDGET_H

#include <QWidget>
#include <QDate>
#include <QList>
#include <QRect>
#include <QPainter>
#include <QDate>
#include <QTime>
#include <QRandomGenerator>
#include <QColor>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTimer>
#include <QStringList>
#include <QRandomGenerator>



struct CalendarEvent
{
    int id;
    QDate date;
    QTime start;
    QTime end;
    QString title;
    mutable QColor color;
};

class RandomGreetingsWidget : public QWidget
{
    Q_OBJECT
public slots:
    void updateGreeting()
    {
        static QStringList greetings = {
            "你既可以爱，又可以被爱，这是世界上最美好的事情。",
            "不必行色匆匆，不必光芒四射，不必成为别人，只需做自己。",
            "心之如何，有似万丈迷津，遥亘千里，其中并无舟子可以渡人，除了自渡，他人爱莫能助。",
            "喜欢海，喜欢花，喜欢日出和日落，浪漫的年纪别活的太无趣。",
            "慢慢变好，我是你也是。",
            "深处沟壑，依然有仰望星空的权利。",
            "大地丰盈，人间并不寂寥。",
            "星星应该哈哈大笑，反正宇宙是个偏僻的地方。",
            "所谓无底深渊，下去，也是前程万里。",
            "山川是不卷收的文章，日月为你掌灯伴读。",
            "别慌，月亮也正在大海某处迷茫。",
            "心怀浪漫宇宙，珍惜人间日常。",
            "你瞄准月亮，即使迷失，也在星辰之间。",
            "岁岁常欢愉，万事皆胜意。",
            "挑战是生活的常态，但迈过去，就是欢喜顺遂。",
            "有烦恼的功夫，不如用来读书。",
            "山河浩瀚，宇宙浪漫，值得一看。",
            "种一棵树最好的时间是十年前，其次是现在。",
            "当善良遇见了温柔便是人间绝配。",
            "愿你阳光下像个孩子，风雨里像个大人。",
            "我们各自努力，最高处见。",
            "前路浩浩荡荡，万物皆可期待。",
            "等苦尽甘来的那一天，山河星月都做贺礼。",
            "不要着急，最好的总在不经意之间出现。",
            "向前看，你应该越活越开阔，越活越坚定。",
            "明智的放弃胜过盲目的执著。",
            "原神启动！！！",
            "原神启动！！！"
        };

        int index = QRandomGenerator::global()->bounded(greetings.size());
        textEdit->setText(greetings[index]);
    }
public:
    RandomGreetingsWidget()
    {
        this->setMinimumWidth(250);
        this->setMaximumWidth(250);
        auto *layout = new QVBoxLayout(this);
        textEdit = new QTextEdit();
        textEdit->setReadOnly(true);
        layout->addWidget(textEdit);

        updateGreeting();
    }

private:
    QTextEdit *textEdit;


};


class RandomImageWidget : public QWidget
{
    Q_OBJECT
public slots:
    void updateImage() {
        static QStringList imagePaths =
        {
            ":/tool/1.jpg",
            ":/tool/2.jpg",
            ":/tool/3.jpg",
            ":/tool/4.jpg",
            ":/tool/5.jpg",
            ":/tool/6.jpg",
            ":/tool/7.jpg",
            ":/tool/8.jpg",
            ":/tool/9.jpg",
            ":/tool/10.jpg",
            ":/tool/11.jpg",
            ":/tool/12.jpg"
        };

        int index = QRandomGenerator::global()->bounded(imagePaths.size());
        QPixmap pixmap(imagePaths[index]);
        imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
public:
    RandomImageWidget()
    {
        this->setMinimumWidth(270);
        this->setMaximumWidth(270);
        auto *layout = new QVBoxLayout(this);
        imageLabel = new QLabel();
        layout->addWidget(imageLabel);

        updateImage();
    }

private:
    QLabel *imageLabel;


};

class WeekCalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeekCalendarWidget(int userid, QWidget *parent = nullptr);
    ~WeekCalendarWidget();
    void addEvent(const QDate &date, const QTime &startTime, const QTime &endTime, const QColor &color, const QString &title, const int eventId);
    void setWeek(const QDate &date);
    void getId(int Id);
    void editEventNote(int eventId);



private:
    static const int RowsPerHour = 6;
    QGridLayout *gridLayout;
    QMap<QPair<QDate, QTime>, QPushButton*> eventButtons;
    QDate currentDate;
    QLabel *yearLabel;
    QLabel *dayLabels[7];


    void clearWeek();
    int timeToRow(const QTime &time) const;
    int calculateDurationInRows(const QTime &startTime, const QTime &endTime) const;
    int userId;

public slots:
    void goToNextWeek();
    void goToPreviousWeek();
    void jumpToDate(const QDate &date);
    void updateWeek();
};

#endif // WEEKLYCALENDARWIDGET_H
