#include "uploadtask.h"
#include"uploadlayout.h"
#include"transformwidget.h"
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

    uploadFileInfo->uploadStatus=UPLOAD_NOT;//设置未上传状态
    filedataProgress* upProgress=new filedataProgress;
    upProgress->setName(uploadFileInfo->fileName);
    uploadFileInfo->fdp=upProgress;
    uploadlayout::getInstant()->getVLayout()->insertWidget(0,upProgress);
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

   UploadFileInfo* temp=m_filelist.at(0);
   return temp;
}

//删除任务
void uploadtask::delUploadTask()
{
    //1.取出任务，判断该任务的状态，如果是上传完成，上传失败，上传成功，该任务是会被删除掉
    //2.将该任务从列表中移除
    //3.删除进度条，并删除该任务的资源
    if(isEmpty()){
        return;
    }

    UploadFileInfo* temp=m_filelist.at(0);
    if(temp->uploadStatus==UPLOAD_FINISHED||
       temp->uploadStatus==UPLOAD_FAILD||
       temp->uploadStatus==UPLOAF_FILE_EXISTE  )
    {
        //删除该任务
        qDebug()<<"删除任务";
        m_filelist.removeAt(0);

        uploadlayout::getInstant()->getVLayout()->removeWidget(temp->fdp);//将进度条从布局中移除
        delete temp->fdp;
        delete temp;
    }
}

//清空列表
void uploadtask::clearList()
{

}
