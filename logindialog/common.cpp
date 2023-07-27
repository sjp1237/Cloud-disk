#include "common.h"
#include<QCryptographicHash>
#include"des.h"
#include<QMap>
#include<QMessageBox>
#include<QDir>
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
    unsigned char pwd_data[1024]={0};
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


QString Common::getFileMd5(QString filePath)
{
    QFile localFile(filePath);

    if (!localFile.open(QFile::ReadOnly))
    {
        qDebug() << "file open error.";
        return 0;
    }

    QCryptographicHash ch(QCryptographicHash::Md5);

    quint64 totalBytes = 0;
    quint64 bytesWritten = 0;
    quint64 bytesToWrite = 0;
    quint64 loadSize = 1024 * 4;
    QByteArray buf;

    totalBytes = localFile.size();
    bytesToWrite = totalBytes;

    while (1)
    {
        if(bytesToWrite > 0)
        {
            buf = localFile.read(qMin(bytesToWrite, loadSize));
            ch.addData(buf);
            bytesWritten += buf.length();
            bytesToWrite -= buf.length();
            buf.resize(0);
        }
        else
        {
            break;
        }

        if(bytesWritten == totalBytes)
        {
            break;
        }
    }

    if (localFile.isOpen()) {
        localFile.close();
    }
    QByteArray md5 = ch.result();
    return md5.toHex();
}


QString Common::getBoundary() {

    //随机生成16个字符
    char randoms[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    //随机种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QString temp;
    int len = strlen(randoms);
    for (int i=0; i<16; i++) {
        int rand = qrand() % len;
        temp[i] = randoms[rand];
    }

    qDebug() << "temp:" << temp;

    //QString randText = "DQAR0QX1ojAyzAre";  //0-9a-zA-Z
    QString boundary = "------WebKitFormBoundary" + temp;

    return boundary;
}


void Common::writeRecord(QString user, QString fileName, QString code, QString path)
{
    qDebug()<<path;
    QDir dir(path);
    if(!dir.exists())
    {
        //该目录不存在，则创建该目录
        if(dir.mkpath(path))
        {
            qDebug()<<"目录创建成功";
        }
        else {
            qDebug()<<"目录创建失败";
            return;
        }
    }

      // conf/record/milo.txt
    QString confFileName=QString("%1/%2.txt").arg(path).arg(user);
    qDebug()<<confFileName;
    QFile file(confFileName);
    //先读取文件中的所有数据

    QByteArray s;
    if(file.exists())
    {
       if(file.open(QFile::ReadOnly)){
           s=file.readAll();
           file.close();
       }
       else {
           qDebug()<<"打开文件失败";
           return;
       }
  }

    if(file.open(QFile::WriteOnly))
    {
        QTime curTime=QTime::currentTime();
        QString timeStr=curTime.toString("hh:mm:ss");

        QDate curDate=QDate::currentDate();
        QString dateStr=curDate.toString("yy/MM/dd");

        QString codeDes=getCodeDes(code);
        //xxx.jpg   2020/11/20 16:02:01 上传成功
        QString data=QString("%1\t%2\t%3\t%4\r\n").arg(fileName).arg(dateStr).arg(timeStr).arg(codeDes);

        QString data1=QString("%1\t%2\t%3\t%4\r\n").arg("文件").arg("日期").arg("时间").arg("状态");
        file.write(data.toLocal8Bit());
        if(s.size()!=0)
        {
             file.write(s);
        }

        file.close();
    }
}

QString Common::getCodeDes(QString code)
{

        /*
        005：上传的文件已存在
        006: 秒传成功
        007: 秒传失败
        008: 上传成功
        009: 上传失败
        090: 下载成功
        091: 下载失败
        013:  删除成功
        */
        QString str;
        if (code == "005") {
            str = "上传的文件已存在";
        } else if (code == "006") {
            str = "秒传成功";
        } else if (code == "007") {
            str = "秒传失败";
        } else if (code == "008") {
            str = "上传成功";
        } else if (code == "009") {
            str = "上传失败";
        } else if (code == "090") {
            str = "下载成功";
        } else if (code == "091") {
            str = "下载失败";
        }else if(code=="013")
        {
            str="删除成功";
        }else if(code=="004"){
            str="删除失败";
        }

        return str;
}
