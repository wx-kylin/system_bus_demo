#include "sysdbusregister.h"

#include <QDebug>
#include <QProcess>

SysdbusRegister::SysdbusRegister()
{
}

SysdbusRegister::~SysdbusRegister()
{
}

int SysdbusRegister::exitService(int num)
{
    //    QProcess::execute("ukui-control-center");
        qDebug() << "exit " << num;
        return 0;
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
