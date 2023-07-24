#ifndef DOWNLOADTASK_H
#define DOWNLOADTASK_H
#include <QString>
#include <QList>
#include<QFileInfo>
#include "filedataprogress.h"
#include"common.h"
#include"fileinfo.h"

//下载任务类

#define DOWNLOAD_NOT 0
#define DOWNLOADING  1
struct DownloadFileInfo
{
    QString md5;            //文件的md5值
    QString url;            //文件的url
    filedataProgress *fdp;  //进度条
    bool isShareTask;       //是否是共享文件任务, true是共享文件任务,false不是共享文件任务
    QFile* file;
    QString fileName;

    int status;
};


class downloadtask
{
public:
    downloadtask();
    //添加文件到上传任务列表中
    int appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask=false);

    //判断任务列表是否为空
    bool isEmpty();

    //取出任务
    DownloadFileInfo* takeTask();

    //删除任务
    void delUploadTask();

    //清空列表
    void clearList();


private:
    QList<DownloadFileInfo*> m_filelist;
};

#endif // DOWNLOADTASK_H
