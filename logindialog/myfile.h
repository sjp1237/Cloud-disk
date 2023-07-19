#ifndef MYFILE_H
#define MYFILE_H

#include <QWidget>
#include<QMenu>

#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include"common.h"
#include"logininfoinstance.h"
#include"analyjsondata.h"
namespace Ui {
class myfile;
}

class myfile : public QWidget
{
    Q_OBJECT

public:
    explicit myfile(QWidget *parent = nullptr);
    ~myfile();

    void myfileInit();
    void setWidgetMemu();
    void setMenuAction();

    void setActionConnect();



private:
    enum MyFileDisplay { Normal, Asc, Desc};
    enum DealFile{Share,Delete,Download,Show};

    void getFileCount(MyFileDisplay cmd=Normal);
    void getFileList(MyFileDisplay cmd=Normal);

    void dealfile(DealFile cmd);
    void shareFile(FileInfo *fileInfo);
    void deleteFile(FileInfo *fileInfo);
    void showFileProperty(FileInfo *fileInfo);
    void uploadFile();
//    void uploadFile(UploadFileInfo *uploadFileInfo);
    void addUploadFiles();
    void addDownloadFiles();
    void getMd5Str();

    void refreshFileList();//显示文件列表
    void clearFileList();//删除文件信息

    void clearFileItem();//删除文件列表
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
    logininfoinstance* m_logininfo;
    QNetworkAccessManager* m_manager;

    QList<FileInfo*> m_fileInfoList;
    int myfileCount=0;
};

#endif // MYFILE_H
