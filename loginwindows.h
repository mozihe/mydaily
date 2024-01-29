#ifndef LOGINWINDOWS_H
#define LOGINWINDOWS_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QCheckBox>

class loginwindows : public QWidget
{
    Q_OBJECT
public:
    explicit loginwindows(QWidget *parent = nullptr);

private slots:

    void onLoginButtonClicked();
    void onShowPasswordCheckBoxToggled(bool checked);
    void onSwitchToRegisterButtonClicked();

protected:
    void paintEvent(QPaintEvent *event) override;

private:

    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QLabel *statusLabel;
    QCheckBox *showPasswordCheckBox;
    QPushButton *switchToRegisterButton;

signals:

    void switchWindow();
    void userLoggedIn(int userId);

};

#endif // LOGINWINDOWS_H
