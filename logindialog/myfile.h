#ifndef MYFILE_H
#define MYFILE_H

#include <QWidget>
#include<QMenu>
#include<QTimer>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include"common.h"
#include"logininfoinstance.h"
#include"analyjsondata.h"
#include"uploadtask.h"
#include"downloadtask.h"
namespace Ui {
class myfile;
}

class myfile : public QWidget
{
    Q_OBJECT
      enum MyFileDisplay { Normal, Asc, Desc};
public:
    explicit myfile(QWidget *parent = nullptr);
    ~myfile();

    void myfileInit();
    void setWidgetMemu();
    void setMenuAction();

    void setActionConnect();

    void showMyfile();
     void changerUser();
private:
    enum DealFile{Share,Delete,Download,Show};
    void getFileCount(MyFileDisplay cmd=Normal);
    void getFileList(MyFileDisplay cmd=Normal);
    void dealfile(DealFile cmd);
    void shareFile(FileInfo *fileInfo);//分析文件
    void deleteFile(FileInfo *fileInfo,int index);//删除文件
    void showFileProperty(FileInfo *fileInfo);//显示文件属性



//    void uploadFile(UploadFileInfo *uploadFileInfo);
    void addUploadFiles();
    void addDownloadFiles();
    void getMd5Str();

    void refreshFileList();//显示文件列表
    void clearFileList();//删除文件列表信息
    void clearFileItem();//删除文件列表


    //上传文件
    void addUploadFile();
    void uploadFileAction();
    void uploadFile(UploadFileInfo *uploadFileInfo);

    //下载文件
    void addDownloadFile(FileInfo *fileInfo);
    void DownloadFileAction();
    void DownloadFile(UploadFileInfo *uploadFileInfo);


    void checkTaskList();
private:
    Ui::myfile *ui;
    QMenu* m_fileMenu;
    QMenu* m_blankMenu;

    //右键点击文件产生的菜单
    QAction* m_downloadAction;//下载
    QAction* m_deleteAction;  //删除
    QAction *m_shareAction;   //分享
    QAction *m_propertyAction;//属性

    //右键点击空白产生的菜单
    QAction *m_downloadAscAction;  //按下载量升序
    QAction *m_downloadDescAction; //按下载量降序
    QAction *m_refreshAction;      //更新
    QAction *m_uploadAction;       //上传

    Common* m_common;
    logininfoinstance* m_logininfo; //登录信息
    QNetworkAccessManager* m_manager; //http管理
    QList<FileInfo*> m_fileInfoList; //用户的文件信息
    int myfileCount=0;

    uploadtask* m_uploadtask;//上传文件列表
    QTimer m_uploadTimer;

    downloadtask* m_downloadtask; //下载文件任务列表
    QTimer m_downloadTimer;
};

#endif // MYFILE_H
