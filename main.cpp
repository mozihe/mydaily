#include "loginwindows.h"
#include "registerwindows.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "calendarapp.h"
#include <QApplication>
#include "usersettingwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/background/logal.jpg"));

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "mydaily_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    loginwindows loginWindow;
    loginWindow.show();
    registerwindows registerWindow;

    QObject::connect(&loginWindow, &loginwindows::switchWindow, [&](){
        loginWindow.hide();
        registerWindow.show();
    });

    QObject::connect(&registerWindow, &registerwindows::switchWindow, [&](){
        registerWindow.hide();
        loginWindow.show();
    });

    CalendarApp window;



    QObject::connect(&loginWindow, &loginwindows::userLoggedIn, &window, &CalendarApp::onUserLoggedIn);

    return a.exec();
}
