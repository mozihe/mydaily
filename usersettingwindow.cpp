#include "usersettingwindow.h"
#include "databaseuser.h"

UserSettingsWindow::UserSettingsWindow(int id, QWidget *parent)
    : QDialog(parent),
      nicknameEdit(new QLineEdit(this)),
      uploadAvatarButton(new QPushButton(tr("上传头像"), this)),
      saveButton(new QPushButton(tr("保存"), this)),
      cancelButton(new QPushButton(tr("取消"), this)),
      imagePreview(new QLabel(this))
{
    setFixedSize(400, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->addSpacing(20);

    nicknameEdit->setPlaceholderText(tr("昵称"));
    nicknameEdit->setMaxLength(20);
    nicknameEdit->setFixedWidth(200);
    mainLayout->addWidget(nicknameEdit, 0, Qt::AlignCenter);

    getId(id);

    uploadAvatarButton->setFixedWidth(200);
    mainLayout->addWidget(uploadAvatarButton, 0, Qt::AlignCenter);

    mainLayout->addSpacing(10);

    imagePreview->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(imagePreview);

    mainLayout->addSpacing(10);


    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonLayout);

    connect(uploadAvatarButton, &QPushButton::clicked, this, &UserSettingsWindow::onUploadAvatarClicked);
    connect(saveButton, &QPushButton::clicked, this, &UserSettingsWindow::onSaveClicked);
    connect(cancelButton, &QPushButton::clicked, this, &UserSettingsWindow::reject);

    setWindowTitle(tr("用户设置"));
}

void UserSettingsWindow::onUploadAvatarClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png *.jpg *.jpeg)"));
    if (!fileName.isEmpty()) {

        QString uniqueFileName = QUuid::createUuid().toString(QUuid::WithoutBraces) + "." + QFileInfo(fileName).suffix();

        QString userDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        QString savePath = userDataPath + "/avatars/" + uniqueFileName;

        QDir dir(userDataPath + "/avatars/");
        if (!dir.exists()) {
            dir.mkpath(".");
        }

        QImage image(fileName);
        if (image.save(savePath)) {
            avatarPath = savePath;
            QPixmap pixmap = QPixmap::fromImage(image).scaled(100, 100, Qt::KeepAspectRatio);
            imagePreview->setPixmap(pixmap);
            imagePreview->setAlignment(Qt::AlignCenter);
        }
    }
}

QString UserSettingsWindow::getNickname() const
{
    return nicknameEdit->text();
}

QString UserSettingsWindow::getAvatarPath() const
{
    return avatarPath;
}

void UserSettingsWindow::onSaveClicked()
{
    QString nickname = nicknameEdit->text();
    QString newAvatarPath = getAvatarPath();

    databaseuser dbUser;
    if (!dbUser.openDatabase())
        return;

    if (!nickname.isEmpty())
    {
        dbUser.updateNickname(userId, nickname);
    }

    if (!newAvatarPath.isEmpty())
    {
        dbUser.updateAvatarPath(userId, newAvatarPath);
    }

    emit userDetailsUpdated();
    accept();
}

void UserSettingsWindow::getId(int userId)
{
    this->userId = userId;
}
void UserSettingsWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap(":/background/background1.jpg");
    painter.drawPixmap(rect(), pixmap);
}
