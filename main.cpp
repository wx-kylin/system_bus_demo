#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusError>

#include <QDebug>

#include "sysdbusregister.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setOrganizationName("Kylin Team");
    a.setApplicationName("system-bus-demo-service");

    QDBusConnection systemBus = QDBusConnection::systemBus();
    if (!systemBus.registerService("com.demo.systemdbus")){
        qCritical() << "QDbus register service failed reason:" << systemBus.lastError();
        exit(1);
    }

    if (!systemBus.registerObject("/", new SysdbusRegister(), QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals)){
        qCritical() << "QDbus register object failed reason:" << systemBus.lastError();
        exit(2);
    }
    qDebug() << "ok";
    return a.exec();
}
