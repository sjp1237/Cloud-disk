#include "common.h"
#include<QCryptographicHash>
#include"des.h"
#include<QMap>
#include<QMessageBox>
Common::Common()
{
    m_manger=new QNetworkAccessManager;
}

 QNetworkAccessManager* Common::getNetworkManger()
 {
     return m_manger;
 }
Common* Common::instant=new Common();
Common* Common::getInstant()
{
    return instant;
}


//读取文件数据
//title选择登录信息，还是服务器的信息
//key是选择QJson对象中某个具体的信息。
QString Common::getConfValue(QString title, QString key, QString path)
{
       QFile file(path);
      // qDebug()<<path;
        if(file.open(QFile::ReadOnly)==false)
        {
            qDebug()<<"打开配置文件失败";
            return QString();
        }
        QByteArray s=file.readAll();
        file.close();

        //将Json字符串转换为QJsonDocument对象
        QJsonDocument document=QJsonDocument::fromJson(s);
        if(document.isObject()){
            QJsonObject object=document.object();
             QJsonValue value=object[title];
             if(value.isObject())
             {

                 QJsonObject object1=value.toObject();
                 if(!object1.contains(key)){
                     qDebug()<<"key值错误";
                     return QString();
                 }
                 QJsonValue value1=object1[key];
                 QString res=value1.toString();
                 return res;
             }
        }
}

//登录账号和密码 写入到配置文件当中
void Common::writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path)
{
    //获取ip地址
    QString ip = getConfValue("web_server", "ip");
    QString port = getConfValue("web_server", "port");
    QMap<QString,QVariant> web_server;
    web_server.insert("ip",ip);
    web_server.insert("port",port);
    //进行des加密
    unsigned char usr_data[1024]={0};
    int length1=0;
    //toLocal8Bit是将QString转换成QByteArray,data转换成char*数据，QString不能直接转换成char*。
    int res=DesEnc((unsigned char*)user.toLocal8Bit().data(),user.toLocal8Bit().length(),usr_data,&length1);
    if(res!=0)
    {
        qDebug()<<"账号加密失败";
        return;
    }
    unsigned char pwd_data[1024];
    int length2=0;
    res=DesEnc((unsigned char*)pwd.toLocal8Bit().data(),pwd.toLocal8Bit().length(),pwd_data,&length2);

    if(res!=0)
    {
        qDebug()<<"密码加密失败";
        return;
    }

    //进base64加密
    QByteArray usr_base64=QByteArray((const char*)usr_data,length1).toBase64();
    QByteArray pwd_base64=QByteArray((const char*)pwd_data,length2).toBase64();

    QMap<QString,QVariant> login;
    login.insert("user",usr_base64);
    login.insert("pwd",pwd_base64);
    if(isRemeber)
    {
          login.insert("remember","yes");
    }else{
          login.insert("remember","no");
    }


    QMap<QString, QVariant> json;
    json.insert("web_server", web_server);
    json.insert("login", login);

    QJsonDocument jsonDocument = QJsonDocument::fromVariant(json);
    if ( jsonDocument.isNull() == true)
    {
        qDebug() << "QJsonDocument::fromVariant错误";
        return;
    }

    QFile file(CONF_FILE);
    if(!file.open(QFile::WriteOnly)!=0)
    {
            qDebug()<<"打开文件失败";
            return;
    }

    file.write(jsonDocument.toJson());
    file.close();
}

// 将服务器的ip和port写入到配置文件
void Common::writeWebInfo(QString ip, QString port, QString path)
{

    QMap<QString,QVariant> web_server;
    web_server.insert("ip",ip);
    web_server.insert("port",port);

    QString usr_base64=getConfValue("login","user");
    QString pwd_base64=getConfValue("login","pwd");
    QString remember=getConfValue("login","remember");

    QMap<QString,QVariant> login;
    login.insert("user",usr_base64);
    login.insert("pwd",pwd_base64);
    login.insert("remember",remember);

    QMap<QString, QVariant> json;
    json.insert("web_server", web_server);
    json.insert("login", login);

    QJsonDocument jsonDocument = QJsonDocument::fromVariant(json);
    if ( jsonDocument.isNull() == true)
    {
        qDebug() << "QJsonDocument::fromVariant错误";
        return;
    }

    QFile file(CONF_FILE);
    if(!file.open(QFile::WriteOnly)!=0)
    {
            qDebug()<<"打开文件失败";
            return;
    }

    file.write(jsonDocument.toJson());
    file.close();

    qDebug()<<"配置成功";
}

//md5加密字符串
QString Common::getStrMd5(QString str)
{
    //
    QByteArray arr=QCryptographicHash::hash(str.toLocal8Bit(),QCryptographicHash::Md5);
    return arr.toHex();

}
