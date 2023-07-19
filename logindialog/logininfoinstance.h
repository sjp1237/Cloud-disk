#ifndef LOGININFOINSTANCE_H
#define LOGININFOINSTANCE_H

#include <QObject>
#include<QString>

class logininfoinstance : public QObject
{
    Q_OBJECT
public:
   logininfoinstance(logininfoinstance*)=delete;

    static logininfoinstance* instant;

    static logininfoinstance* getInstant();
signals:

public slots:


public:

    void setUser(QString user);
    void setToken(QString token);
    void setIp(QString ip);
    void setPort(QString port);

    QString user();
    QString token();
    QString ip();
    QString port();
private:

     explicit logininfoinstance(QObject *parent = nullptr);
    QString m_user;
    QString m_token;
    QString m_ip;
    QString m_port;
};

#endif // LOGININFOINSTANCE_H
