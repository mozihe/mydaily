#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include <QTime>
#include <QTimer>

class AnalogClockWidget : public QWidget {
    Q_OBJECT

public:
    explicit AnalogClockWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawClock(QPainter *painter);
};

class TextDisplayWidget : public QWidget {
    Q_OBJECT

public:
    explicit TextDisplayWidget(QWidget *parent = nullptr);

public slots:
    void updateDisplay();

private:
    QLabel *timeLabel;
    QLabel *lunarDateLabel;
    QLabel *festivalAndTermsLabel;

};

TextDisplayWidget* createTextDisplayWidget();
AnalogClockWidget* createAnalogClockWidget();
#endif // DATETIMEWIDGET_H
