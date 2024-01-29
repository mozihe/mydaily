#ifndef USERSETTINGWINDOW_H
#define USERSETTINGWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QImage>
#include <QUuid>
#include <QDir>

class UserSettingsWindow : public QDialog {
    Q_OBJECT

public:
    UserSettingsWindow(int id, QWidget *parent = nullptr);
    QString getNickname() const;
    QString getAvatarPath() const;
    void onSaveClicked();
    void getId(int userId);
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLineEdit *nicknameEdit;
    QPushButton *uploadAvatarButton;
    QLabel *imagePreview;
    QString avatarPath;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    int userId;

private slots:
    void onUploadAvatarClicked();
signals:
    void userDetailsUpdated();
};


#endif // USERSETTINGWINDOW_H
