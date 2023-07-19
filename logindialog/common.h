#ifndef COMMON_H
#define COMMON_H
#include<QString>
#include<QFile>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QDebug>
#include<QByteArray>
#include<QNetworkAccessManager>
#define USER_REG        "^[a-zA-Z\\d_@#-\*]\{3,16\}$"    //用户名
#define PASSWD_REG      "^[a-zA-Z\\d_@#-\*]\{6,18\}$"
#define PHONE_REG       "1\\d\{10\}"
#define EMAIL_REG       "^[a-zA-Z\\d\._-]\+@[a-zA-Z\\d_\.-]\+(\.[a-zA-Z0-9_-]\+)+$"
#define IP_REG          "((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)"
#define PORT_REG        "^[1-9]$|(^[1-9][0-9]$)|(^[1-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9]$)|(^[1-6][0-5][0-5][0-3][0-5]$)"


#define CONF_FILE "./conf/cfg.json" //配置文件的路径

class Common
{
    static Common* instant;
    QNetworkAccessManager* m_manger;
public:
    Common();
    static Common* getInstant();
    //读取文件数据
    //title
    QString getConfValue(QString title, QString key, QString path=CONF_FILE);

    //写入数据到文件
    void writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path=CONF_FILE);

    // 服务器信息，写入配置文件
    void writeWebInfo(QString ip, QString port, QString path=CONF_FILE);

    //md5加密字符串
    QString getStrMd5(QString str);

    //获取文件的md5值
    QString getFileMd5(QString filePath);
    QNetworkAccessManager* getNetworkManger();

    QString getBoundary();
};
#endif // COMMON_H
