#include "loginwindows.h"
#include "databaseuser.h"

loginwindows::loginwindows(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("登录");
     setFixedSize(400, 300);

     usernameLineEdit = new QLineEdit(this);
     usernameLineEdit->setMaximumWidth(200);
     usernameLineEdit->setMaxLength(12);
     passwordLineEdit = new QLineEdit(this);
     passwordLineEdit->setEchoMode(QLineEdit::Password);
     passwordLineEdit->setMaxLength(12);
     passwordLineEdit->setMaximumWidth(200);

    loginButton = new QPushButton("登录", this);
    loginButton->setStyleSheet("background-color: rgb(200, 140, 210);");

    showPasswordCheckBox = new QCheckBox("显示密码", this);
    showPasswordCheckBox->setStyleSheet("color: rgb(255, 255, 255);");
    connect(showPasswordCheckBox, &QCheckBox::toggled, this, &loginwindows::onShowPasswordCheckBoxToggled);

    statusLabel = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch(1);
    QLabel *l1 = new QLabel("用户名:");
    l1->setStyleSheet("color: rgb(255, 255, 255);");
    layout->addWidget(l1, 0, Qt::AlignCenter);
    layout->addWidget(usernameLineEdit, 0, Qt::AlignCenter);
    QLabel *l2 = new QLabel("密码:");
    l2->setStyleSheet("color: rgb(255, 255, 255);");
    layout->addWidget(l2, 0, Qt::AlignCenter);
    layout->addWidget(passwordLineEdit, 0, Qt::AlignCenter);
    layout->addWidget(showPasswordCheckBox, 0, Qt::AlignCenter);
    layout->addStretch(1);
    loginButton->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    layout->addWidget(loginButton, 0, Qt::AlignCenter);
    layout->addStretch(1);
    statusLabel->setStyleSheet("color: rgb(255, 255, 255);");
    layout->addWidget(statusLabel, 0, Qt::AlignCenter);
    layout->addStretch(1);

    switchToRegisterButton = new QPushButton("转到注册", this);
    switchToRegisterButton->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    layout->addWidget(switchToRegisterButton, 0, Qt::AlignCenter);
    connect(switchToRegisterButton, &QPushButton::clicked, this, &loginwindows::onSwitchToRegisterButtonClicked);

    connect(loginButton, &QPushButton::clicked, this, &loginwindows::onLoginButtonClicked);
}

void loginwindows::onLoginButtonClicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    databaseuser dbHelper;
    if (!dbHelper.openDatabase())
    {
        statusLabel->setText("数据库错误");
        return;
    }

    if (username.isEmpty() || password.isEmpty())
    {
        statusLabel->setText("用户名和密码不能为空");
        return;
    }

    if (!dbHelper.isUsernameExist(username))
    {
        statusLabel->setText("用户名不存在");
        return;
    }

    if (!dbHelper.validateUser(username, password))
    {
        statusLabel->setText("密码错误");
        return;
    }


    if (dbHelper.validateUser(username, password))
    {
        int userId = dbHelper.getUserId(username);
        this->hide();
        emit userLoggedIn(userId);
        return;
    }
}

void loginwindows::onShowPasswordCheckBoxToggled(bool checked)
{
    passwordLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
}

void loginwindows::onSwitchToRegisterButtonClicked()
{
    emit switchWindow();
}

void loginwindows::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap(":/background/background1.jpg");
    painter.drawPixmap(rect(), pixmap);
}
