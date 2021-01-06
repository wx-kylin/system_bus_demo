#ifndef SYSDBUSREGISTER_H
#define SYSDBUSREGISTER_H

#include <QObject>
#include <QCoreApplication>
#include <QProcess>
#include <QFile>
#include <QSettings>

class SysdbusRegister : public QObject
{
    Q_OBJECT

    Q_CLASSINFO("D-Bus Interface", "com.demo.interface")
public:
    explicit SysdbusRegister();
    ~SysdbusRegister();
private:

public slots:
    Q_SCRIPTABLE int exitService(int num);
    Q_SCRIPTABLE QString GetComputerInfo();
};

#endif // SYSDBUSREGISTER_H
