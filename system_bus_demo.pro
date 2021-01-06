QT += core dbus
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demoDbus
TEMPLATE = app

CONFIG += c++11 console link_pkgconfig
CONFIG -= app_bundle

DESTDIR = .
INCLUDEPATH += . \
    /usr/include/polkit-qt5-1/

inst1.files += conf/com.demo.systemdbus.service
inst1.path = /usr/share/dbus-1/system-services/
inst2.files += conf/com.demo.systemdbus.conf
inst2.path = /etc/dbus-1/system.d/
inst3.files += conf/com.demo.systemdbus.policy
inst3.path = /usr/share/polkit-1/actions/

target.source += $$TARGET
target.path = /usr/bin
INSTALLS += \
    target \
    inst1 \
    inst2 \
    inst3 \

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS    += -L/usr/lib/x86_64-linux-gnu/ -lpolkit-qt5-core-1

SOURCES += \
        main.cpp \
        sysdbusregister.cpp

DISTFILES += \
    conf/com.demo.systemdbus.conf \
    conf/com.demo.systemdbus.service

HEADERS += \
    sysdbusregister.h

