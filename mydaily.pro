QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendarapp.cpp \
    databaseuser.cpp \
    datetimewidget.cpp \
    loginwindows.cpp \
    main.cpp \
    registerwindows.cpp \
    usersettingwindow.cpp \
    weeklycalendarwidget.cpp

HEADERS += \
    calendarapp.h \
    databaseuser.h \
    datetimewidget.h \
    loginwindows.h \
    nodate.h \
    registerwindows.h \
    usersettingwindow.h \
    weeklycalendarwidget.h

FORMS +=

TRANSLATIONS += \
    mydaily_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
