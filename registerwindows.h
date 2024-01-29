#ifndef REGISTERWINDOWS_H
#define REGISTERWINDOWS_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class registerwindows : public QWidget
{
    Q_OBJECT

public:
    explicit registerwindows(QWidget *parent = nullptr);

signals:
    void switchWindow();

private slots:
    void onRegisterButtonClicked();
    void onSwitchToLoginButtonClicked();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *registerButton;
    QPushButton *switchToLoginButton;
    QLabel *statusLabel;
    QLineEdit *confirmPasswordLineEdit;
};
#endif // REGISTERWINDOWS_H
