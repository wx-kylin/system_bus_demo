#include "sysdbusregister.h"
#include <polkitqt1-authority.h>
//#include <QtDBus/QDBusConnection>
#include <QDBusConnection>
#include <QDBusError>
#include <QDBusMessage>
#include <QDebug>

using namespace PolkitQt1;

SysdbusRegister::SysdbusRegister()
{
}

SysdbusRegister::~SysdbusRegister()
{
}

int SysdbusRegister::exitService()
{
    // message().service() is the service name of the caller
    // We can check if the caller is authorized to the following action
    Authority::Result result;
    qDebug() << message().service();
    SystemBusNameSubject subject(message().service());

    result = Authority::instance()->checkAuthorizationSync("com.demo.systemdbus.exitservice",
             subject , Authority::AllowUserInteraction);
    if (result == Authority::Yes) {
        return 0;
    } else {
        return -1;
    }
}

QString SysdbusRegister::GetComputerInfo()
{
    QByteArray ba;
    FILE * fp = NULL;
    char cmd[128];
    char buf[1024];
    sprintf(cmd, "dmidecode -t system");

    if ((fp = popen(cmd, "r")) != NULL){
        rewind(fp);
        while (!feof(fp)) {
            fgets(buf, sizeof (buf), fp);
            ba.append(buf);
        }
        pclose(fp);
        fp = NULL;
    }
    return QString(ba);
}
