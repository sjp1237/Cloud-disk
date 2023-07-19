#include "uploadtask.h"

uploadtask::uploadtask()
{

}


//添加文件到上传任务列表中
int uploadtask::appendUploadTask(QString filePath)
{

    QFileInfo* fileinfo=new QFileInfo(filePath);
   if(fileinfo->size()>30*1024*1024)
   {
       //如果文件大于30mb，则放弃该文件
       delete fileinfo;
       return -1;
   }

    UploadFileInfo* uploadFileInfo=new UploadFileInfo;
    uploadFileInfo->size=fileinfo->size();
    uploadFileInfo->fileName=fileinfo->fileName();
    uploadFileInfo->filePath=filePath;
    uploadFileInfo->md5=Common::getInstant()->getFileMd5(filePath);


    m_filelist.append(uploadFileInfo);
}


//判断任务列表是否为空
bool uploadtask::isEmpty()
{
    return m_filelist.empty();
}

//取出任务
UploadFileInfo* uploadtask::takeTask()
{
    if(m_filelist.empty()){
        return nullptr;
    }
   return m_filelist.takeAt(0);

}

//删除任务
void uploadtask::delUploadTask()
{

}

//清空列表
void uploadtask::clearList()
{

}
