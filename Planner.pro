QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractcalendarentry.cpp \
    calendar.cpp \
    calendarview.cpp \
    calendaryeardaydelegate.cpp \
    calendaryearmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    request.cpp \
    requestentry.cpp \
    tablecustomselectioneventfilter.cpp \
    testdelegate.cpp \
    testmodel.cpp

HEADERS += \
    abstractcalendarentry.h \
    calendar.h \
    calendarview.h \
    calendaryeardaydelegate.h \
    calendaryearmodel.h \
    mainwindow.h \
    request.h \
    requestentry.h \
    tablecustomselectioneventfilter.h \
    testdelegate.h \
    testmodel.h

FORMS += \
    calendarview.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
