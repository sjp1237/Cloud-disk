#include "common.h"

Common::Common()
{

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
       qDebug()<<path;
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

//登录信息写入到配置文件当中
void Common::writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path)
{

}

// 服务器信息，写入配置文件
void Common::writeWebInfo(QString ip, QString port, QString path)
{

}

//md5加密字符串
QString Common::getStrMd5(QString str)
{

}
