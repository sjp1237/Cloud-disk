#include "logininfoinstance.h"

logininfoinstance::logininfoinstance(QObject *parent) : QObject(parent)
{

}


logininfoinstance* logininfoinstance::instant=new logininfoinstance;

 logininfoinstance* logininfoinstance::getInstant()
 {
     return instant;
 }

void logininfoinstance::setUser(QString user)
{
    m_user=user;
}

void logininfoinstance::setToken(QString token)
{
    m_token=token;
}
void logininfoinstance::setIp(QString ip)
{
    m_ip=ip;
}
void logininfoinstance::setPort(QString port)
{
    m_port=port;
}

QString logininfoinstance::user()
{
    return m_user;
}
QString logininfoinstance::token()
{
    return m_token;
}
QString logininfoinstance::ip()
{
    return m_ip;
}

QString logininfoinstance::port()
{
    return m_port;
}
