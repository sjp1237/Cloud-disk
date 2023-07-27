#ifndef SHAREFILEWIDGET_H
#define SHAREFILEWIDGET_H

#include <QWidget>
#include<QList>
#include<QMenu>
#include"common.h"
#include"fileinfo.h"
#include"logininfoinstance.h"
#include"downloadtask.h"
namespace Ui {
class ShareFileWidget;
}

class ShareFileWidget : public QWidget
{
    Q_OBJECT

public:
    enum DealFile{CancelShare,Save,Download,Show};

    explicit ShareFileWidget(QWidget *parent = nullptr);
    ~ShareFileWidget();


    void dealfile(DealFile cmd);
    void cancelShareFile(FileInfo *fileInfo);//取消分享文件
    void saveFile(FileInfo* fileInfo);//保存文件

    void showFileProperty(FileInfo *fileInfo);//显示文件属性
    void ShareFileWidgetInit();
    void setMenuAction();//设置菜单项

    void setActionConnect();//设置菜单项的槽函数

    void addDownloadFile(FileInfo *fileInfo);//添加任务列表
    void getMd5Str();
    void setWidgetMemu();//设置菜单栏

    void refreshFileList();//显示文件列表
    void clearFileList();//删除文件列表信息
    void clearFileItem();//删除文件列表

    void checkTaskList();
    void getFileCount();//获取分享文件
     void getFileList();//获取文件列表

private:

    QMenu* m_fileMenu;
    QMenu* m_blankMenu;

    //右键点击文件产生的菜单
    QAction* m_downloadAction;//下载
    QAction* m_saveAction;  //保存文件
    QAction *m_CancelShareAction;   //取消分享
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
    int m_sharefileCount=0;

     downloadtask* m_downloadtask; //下载文件任务列表
private:
    Ui::ShareFileWidget *ui;
};

#endif // SHAREFILEWIDGET_H
