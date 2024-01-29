#include "datetimewidget.h"
#include <QVBoxLayout>
#include <QPainter>
#include <QTime>
#include "nodate.h"

TextDisplayWidget::TextDisplayWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(5);
    layout->setSpacing(3);

    timeLabel = new QLabel(this);
    timeLabel->setStyleSheet("color: rgb(255, 255, 255);");
    lunarDateLabel = new QLabel(this);
    lunarDateLabel->setStyleSheet("color: rgb(255, 255, 255);");
    festivalAndTermsLabel = new QLabel(this);
    festivalAndTermsLabel->setStyleSheet("color: rgb(255, 255, 255);");

    layout->addWidget(timeLabel);
    layout->addWidget(lunarDateLabel);
    layout->addWidget(festivalAndTermsLabel);

    timeLabel->setAlignment(Qt::AlignCenter);
    lunarDateLabel->setAlignment(Qt::AlignCenter);
    festivalAndTermsLabel->setAlignment(Qt::AlignCenter);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TextDisplayWidget::updateDisplay);
    timer->start(1000);

    updateDisplay();
}

void TextDisplayWidget::updateDisplay()
{
    QDateTime now = QDateTime::currentDateTime();

    QString nowstring = now.toString("yyyy-MM-dd dddd HH:mm:ss");
    nowstring += " [" + m_ShuXiang[((now.date().year() - 4) % 60) % 12] + "]";
    timeLabel->setText(nowstring);

    QString lunarMD, lunarYear, lunarMonth, lunarDay, lunarTerms, lunarFestival, solarFestival;
    GetLunarDay(now.date(), lunarMD, lunarYear, lunarMonth, lunarDay, lunarTerms, lunarFestival, solarFestival);

    QString lunarDateString = "农历: " + lunarMD + " " + lunarMonth + " " + lunarDay + " " + lunarYear;
    lunarDateLabel->setText(lunarDateString);

    QStringList festivalAndTermsList;
    if (!solarFestival.isEmpty())
        festivalAndTermsList.append(solarFestival);
    if (!lunarFestival.isEmpty())
        festivalAndTermsList.append(lunarFestival);
    if (!lunarTerms.isEmpty())
        festivalAndTermsList.append(lunarTerms);

    QString festivalAndTerms = festivalAndTermsList.join(" | ");
    festivalAndTermsLabel->setText(festivalAndTerms);
    festivalAndTermsLabel->setVisible(!festivalAndTerms.isEmpty());
}

AnalogClockWidget::AnalogClockWidget(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    setMinimumHeight(130);
    setMaximumHeight(130);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QWidget::update));
    timer->start(1000);
}

void AnalogClockWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    drawClock(&painter);
}

void AnalogClockWidget::drawClock(QPainter *painter)
{
    static const QPoint hourHand[3] = {
        QPoint(5, 6),
        QPoint(-5, 6),
        QPoint(0, -25)
    };
    static const QPoint minuteHand[3] = {
        QPoint(3, 6),
        QPoint(-3, 6),
        QPoint(0, -35)
    };
    static const QPoint secondHand[3] = {
        QPoint(1, 8),
        QPoint(-1, 8),
        QPoint(0, -50)
    };

    int clockRadius = 60;
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(127, 127, 127, 191);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(width() / 2, height() / 2);

    painter->save();
    painter->setPen(Qt::black);
    painter->drawEllipse(QPoint(0, 0), clockRadius, clockRadius);
    painter->restore();

    painter->save();
    painter->setPen(Qt::black);
    for (int i = 0; i < 12; ++i) {
        painter->drawLine(clockRadius - 5, 0, clockRadius, 0);
        painter->rotate(30.0);
    }
    painter->restore();

    QTime time = QTime::currentTime();

    painter->save();
    painter->rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter->setBrush(hourColor);
    painter->drawConvexPolygon(hourHand, 3);
    painter->restore();

    painter->save();
    painter->rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter->setBrush(minuteColor);
    painter->drawConvexPolygon(minuteHand, 3);
    painter->restore();

    painter->save();
    painter->rotate(6.0 * time.second());
    painter->setPen(secondColor);
    painter->drawConvexPolygon(secondHand, 3);
    painter->restore();
}

TextDisplayWidget* createTextDisplayWidget()
{
    return new TextDisplayWidget();
}

AnalogClockWidget* createAnalogClockWidget()
{
    return new AnalogClockWidget();
}
