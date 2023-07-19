#ifndef ANALYJSONDATA_H
#define ANALYJSONDATA_H
#include<QObject>
#include<QList>


struct FileInfo
{
    QString user;           //用户名
    QString md5;            //md5
    QString createTime;     //上传时间
    QString fileName;       //文件名称
    int shareStatus;        //共享状态, 0为没有共享， 1为共享
    int pv;                 //文件下载量，下载一次加1
    QString url;            //文件url
    int size;               //文件大小
    QString type;           //文件类型
};

class AnalyJsonData : public QObject
{
    Q_OBJECT


public:
    explicit AnalyJsonData(QObject *parent = nullptr);
   static void  getFileList(QByteArray data,QList<FileInfo*> & filelist);
signals:


public slots:
};

#endif // ANALYJSONDATA_H
