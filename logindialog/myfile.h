#ifndef MYFILE_H
#define MYFILE_H

#include <QWidget>
#include<QMenu>
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
};

#endif // MYFILE_H
