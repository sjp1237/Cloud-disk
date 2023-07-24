#include "downloadtask.h"
#include"downloadlayout.h"
downloadtask::downloadtask()
{

}


//添加文件到上传任务列表中
int downloadtask::appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask)
{

    QFile* file=new QFile(filePath);
    if(!file->open(QFile::WriteOnly)){
        qDebug()<<"文件路径错误";
        return -1;
    }
    DownloadFileInfo* downloadFileInfo=new DownloadFileInfo;
    downloadFileInfo->fileName=fileInfo->fileName;
    downloadFileInfo->file=file;
    downloadFileInfo->md5=fileInfo->md5;
    downloadFileInfo->url=fileInfo->url;
    downloadFileInfo->status=DOWNLOAD_NOT;
    filedataProgress* downProgress=new filedataProgress;
    downProgress->setName(downloadFileInfo->fileName);
    downloadFileInfo->fdp=downProgress;
    downloadLayout::getInstant()->getVLayout()->insertWidget(0,downProgress);
    m_filelist.append(downloadFileInfo);

    return 0;
}


//判断任务列表是否为空
bool downloadtask::isEmpty()
{
    return m_filelist.empty();
}

//取出任务
DownloadFileInfo* downloadtask::takeTask()
{
    if(m_filelist.empty()){
        return nullptr;
    }

   DownloadFileInfo* temp=m_filelist.at(0);
   return temp;
}

//删除任务
void downloadtask::delUploadTask()
{
    //1.将该任务从列表中移除
    //2.删除进度条，并将进度条从布局中移除
    //3.获取file，关闭file,并删除file
    if(isEmpty()){
        return;
    }
    DownloadFileInfo* temp=m_filelist.at(0);
    if(temp!=nullptr)
    {
        m_filelist.removeAt(0);
        downloadLayout::getInstant()->getVLayout()->removeWidget(temp->fdp);
        delete temp->fdp;
        QFile* file=temp->file;
        if(file->isOpen()){
            file->close();
        }

        delete file;

        delete temp;
    }

}

//清空列表
void downloadtask::clearList()
{

}
