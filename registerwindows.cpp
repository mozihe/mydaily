#include "registerwindows.h"
#include "databaseuser.h"

registerwindows::registerwindows(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("注册");
    setFixedSize(400, 300);

    setStyleSheet("registerwindows { background-image: url(:/background/background1.jpg); }");

    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setMaximumWidth(200);
    usernameLineEdit->setMaxLength(12);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMaximumWidth(200);
    passwordLineEdit->setMaxLength(12);
    confirmPasswordLineEdit = new QLineEdit(this);
    confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordLineEdit->setMaximumWidth(200);
    confirmPasswordLineEdit->setMaxLength(12);


    registerButton = new QPushButton("注册", this);
    registerButton->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");

    statusLabel = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch(1);
    QLabel *l1 = new QLabel("用户名:");
    QLabel *l2 = new QLabel("密码:");
    QLabel *l3 = new QLabel("确认密码:");
    l1->setStyleSheet("color: rgb(255, 255, 255);");
    l2->setStyleSheet("color: rgb(255, 255, 255);");
    l3->setStyleSheet("color: rgb(255, 255, 255);");
    layout->addWidget(l1, 0, Qt::AlignCenter);
    layout->addWidget(usernameLineEdit, 0, Qt::AlignCenter);
    layout->addWidget(l2, 0, Qt::AlignCenter);
    layout->addWidget(passwordLineEdit, 0, Qt::AlignCenter);
    layout->addWidget(l3, 0, Qt::AlignCenter);
    layout->addWidget(confirmPasswordLineEdit, 0, Qt::AlignCenter);
    layout->addStretch(1);
    layout->addWidget(registerButton, 0, Qt::AlignCenter);
    statusLabel->setStyleSheet("color: rgb(255, 255, 255);");
    layout->addWidget(statusLabel, 0, Qt::AlignCenter);
    layout->addStretch(1);

    switchToLoginButton = new QPushButton("转到登录", this);
    switchToLoginButton->setStyleSheet("background-color: rgb(200, 140, 210);color: rgb(255, 255, 255);");
    layout->addWidget(switchToLoginButton, 0, Qt::AlignCenter);
    connect(switchToLoginButton, &QPushButton::clicked, this, &registerwindows::onSwitchToLoginButtonClicked);

    connect(registerButton, &QPushButton::clicked, this, &registerwindows::onRegisterButtonClicked);
}

void registerwindows::onRegisterButtonClicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    QString confirmPassword = confirmPasswordLineEdit->text();

    if (username.isEmpty() || password.isEmpty())
    {
        statusLabel->setText("用户名和密码不能为空");
        return;
    }

    if (password != confirmPassword)
    {
        statusLabel->setText("密码错误");
        return;
    }

    databaseuser dbHelper;
    if (!dbHelper.openDatabase())
    {
        statusLabel->setText("数据库错误");
        return;
    }

    if (dbHelper.isUsernameExist(username))
    {
        statusLabel->setText("用户名重复");
        return;
    }

    if (dbHelper.createUser(username, password))
        statusLabel->setText("注册成功");
    else
        statusLabel->setText("注册失败");
}

void registerwindows::onSwitchToLoginButtonClicked()
{
    emit switchWindow();
}

void registerwindows::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap(":/background/background1.jpg");
    painter.drawPixmap(rect(), pixmap);
}
