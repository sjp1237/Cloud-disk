#ifndef UPLOADTASK_H
#define UPLOADTASK_H
#include <QString>
#include <QList>
#include<QFileInfo>
#include "filedataprogress.h"

#define UPLOAD_NOT          0   //未上传
#define UPLOADING           1   //正在上传
#define UPLOAD_FINISHED     2   //上传完成
#define UPLOAD_FAILD        3   //上传失败
#define UPLOAF_FILE_EXISTE  4   //上传的文件已存在

#include"common.h"
struct UploadFileInfo
{
    QString md5;            //文件的md5值
    QString fileName;       //文件名称
    QString filePath;       //文件路径
    qint64 size;            //文件大小
    filedataProgress *fdp;  //进度条
    int uploadStatus;       //0.未上传，1.正在上传，2.上传完成
};


class uploadtask
{
public:
    uploadtask();
    //添加文件到上传任务列表中
    int appendUploadTask(QString filePath);

    //判断任务列表是否为空
    bool isEmpty();

    //取出任务
    UploadFileInfo* takeTask();

    //删除任务
    void delUploadTask();

    //清空列表
    void clearList();


private:
    QList<UploadFileInfo*> m_filelist;
};

#endif // UPLOADTASK_H
