#include "myfile.h"
#include "ui_myfile.h"
#include"mymenu.h"
#include<QDebug>
#include"common.h"
#include"filepropertyiinfodialog.h"

//
myfile::myfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myfile)
{
    ui->setupUi(this);
    //设置窗口的属性
    myfileInit();


    //设置窗口菜单栏
    setWidgetMemu();
    //给菜单添加菜单项
    setMenuAction();
    m_manager=Common::getInstant()->getNetworkManger();
    m_logininfo=logininfoinstance::getInstant();

    //刷新文件列表
    getFileCount(Normal);
}


void myfile::setWidgetMemu()
{
    m_fileMenu=new MyMenu(this);
    m_blankMenu=new MyMenu(this);
    //设置右击鼠标的触发的事件
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget,&QWidget::customContextMenuRequested,this,[=](const QPoint& pos)
    {
        //itemAt获取对应的图标，如果没有则返回空
        QListWidgetItem* item=ui->listWidget->itemAt(pos);
        if(item==nullptr){
            //鼠标在窗口的位置
            qDebug()<<"选中空位置";
            m_blankMenu->exec(QCursor::pos());//显示菜单栏
        }else{
            //鼠标选到对应的文件
            m_fileMenu->exec(QCursor::pos());
            qDebug()<<"选中文件";//显示菜单栏
        }

    });
}


void myfile::setMenuAction()
{
    m_downloadAction=new QAction("下载");
    m_deleteAction=new QAction("删除");
    m_shareAction=new QAction("分享");   //分享
    m_propertyAction=new QAction("属性");//属性


    m_fileMenu->addAction(m_downloadAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_deleteAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_shareAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_propertyAction);

    //右键点击空白产生的菜单
    m_downloadAscAction=new QAction("按下载量升序");  //按下载量升序
    m_downloadDescAction=new QAction("按下载量降序"); //按下载量降序
    m_refreshAction=new QAction("更新");      //更新
    m_uploadAction=new QAction("上传");       //上传


    m_blankMenu->addAction(m_downloadAscAction);
    m_blankMenu->addSeparator();
    m_blankMenu->addAction(m_downloadDescAction);
    m_blankMenu->addSeparator();
    m_blankMenu->addAction(m_refreshAction);
    m_blankMenu->addSeparator();
    m_blankMenu->addAction(m_uploadAction);

    //给菜单选项设置槽函数
    setActionConnect();
}


void myfile::setActionConnect()
{
    //右键文件菜单
    //点击下载文件
    connect(m_downloadAction,&QAction::triggered,this,[=]{
         dealfile(DealFile::Download);
    });

    //点击删除文件
    connect(m_deleteAction,&QAction::triggered,this,[=]{
         dealfile(DealFile::Delete);
    });

    //点击分享文件
    connect(m_shareAction,&QAction::triggered,this,[=]{
         dealfile(DealFile::Share);
    });

    //点击文件属性
    connect(m_propertyAction,&QAction::triggered,this,[=]{
        qDebug()<<"显示文件属性";
        dealfile(DealFile::Show);
    });


    //右键空白菜单
    connect(m_downloadAscAction,&QAction::triggered,this,[=]{
             // qDebug()<<"按下载量降序";
              getFileCount(Desc);
    });


    connect(m_downloadDescAction,&QAction::triggered,this,[=]{
            //  qDebug()<<"按下载量升序";
               getFileCount(Asc);
    });

    connect(m_refreshAction,&QAction::triggered,this,[=]{
            getFileCount(Normal);
              qDebug()<<"更新";
    });

    //上传文件
    connect(m_uploadAction,&QAction::triggered,this,[=]{

              qDebug()<<"上传";
    });
}


//http://119.23.41.13/myfiles?cmd=count
//获取文件数量
void myfile::getFileCount(MyFileDisplay cmd)
{
    //封装http请求
    QNetworkRequest request;
    //从配置文件中获取到ip地址和port端口号
    QString ip=Common::getInstant()->getConfValue("web_server","ip");
    QString port=Common::getInstant()->getConfValue("web_server","port");
  //  QString url=QString("http://%1:%2/myfiles?cmd=count").arg(ip).arg(port);//设置登录的url
     QString url = QString("http://%1:%2/myfiles?cmd=count").arg(ip).arg(port);

    qDebug()<<url;
    request.setUrl(QUrl(url));

    //设置文件类型
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    //将data数据以QJson的格式发送给服务器

    QJsonObject object;
    object.insert("user", m_logininfo->user());
    object.insert("token", m_logininfo->token());

    QJsonDocument doc(object);
    QByteArray data=doc.toJson();
    //发送请求
   // qDebug()<<data;
    QNetworkReply* rely=m_manager->post(request,data);

    connect(rely,&QNetworkReply::readyRead,this,[=]{
        //响应到达,读取所有的数据
        QByteArray s=rely->readAll();
         qDebug() << "服务器返回数据:" << QString(s);
         //将s数据转换为Json对象
         QJsonParseError err;
         QJsonDocument document=QJsonDocument::fromJson(s,&err);

        if(err.error!=QJsonParseError::NoError){
            qDebug()<<"QJson格式错误";
            return;
        }
        //将QJson字符串转换为QJson对象
        QJsonObject object1;
        object1=document.object();

        //获取状态码
        QString value1=object1["code"].toString();
        if(value1=="110"){
            //获取列表成功,获取文件列表
            myfileCount=object1["num"].toString().toInt();
            qDebug()<<"myfileCount："<<myfileCount;
            if(myfileCount>0){
                //文件列表数量大于0
                getFileList(cmd);
            }
        }
        if(value1=="111"){
            //获取失败
            qDebug()<<"获取文件失败";
        }
    });
}
void myfile::getFileList(MyFileDisplay cmd)
{
    QString strCmd;
    if (cmd == MyFileDisplay::Normal) {
        strCmd = "normal";
    } else if (cmd == MyFileDisplay::Asc) {
        strCmd = "pvasc";
    } else if (cmd == MyFileDisplay::Desc) {
        strCmd = "pvdesc";
    }
    //封装http请求
    QNetworkRequest request;
    //从配置文件中获取到ip地址和port端口号
    QString ip=Common::getInstant()->getConfValue("web_server","ip");
    QString port=Common::getInstant()->getConfValue("web_server","port");

    //http://192.168.52.139/myfiles?cmd=normal
    //http://192.168.52.139/myfiles?cmd=asc
    //http://192.168.52.139/myfiles?cmd=pvasc
    QString url = QString("http://%1:%2/myfiles?cmd=%3").arg(ip).arg(port).arg(strCmd);
    qDebug()<<url;
    request.setUrl(QUrl(url));

    //设置数据类型
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    //将data数据以QJson的格式发送给服务器

    QJsonObject object;
    object.insert("user", m_logininfo->user());
    object.insert("token", m_logininfo->token());
    object.insert("start", 0);
    object.insert("count", myfileCount);

    QJsonDocument doc(object);
    QByteArray data=doc.toJson();
    //发送请求
  //  qDebug()<<data;
    QNetworkReply* rely=m_manager->post(request,data);

    connect(rely,&QNetworkReply::readyRead,this,[=]{

        //响应到达,读取所有的数据
        QByteArray s=rely->readAll();
        clearFileList();
        clearFileItem();
        AnalyJsonData::getFileList(s,m_fileInfoList);


        refreshFileList();

        rely->deleteLater();

#if 0
        for(int i=0;i<m_fileInfoList.length();i++)
        {
            /*
            qDebug()<<m_fileInfoList[i]->user;
            qDebug()<<m_fileInfoList[i]->fileName;
            qDebug()<<m_fileInfoList[i]->createTime;
            qDebug()<<m_fileInfoList[i]->shareStatus;
            qDebug()<<m_fileInfoList[i]->pv;
            qDebug()<<m_fileInfoList[i]->url;
            qDebug()<<m_fileInfoList[i]->size;
            qDebug()<<m_fileInfoList[i]->type;
            */
            //更新文件列表到QListWidget
        }
#endif
    });
}

//显示文件列表到QListWidget
void myfile::refreshFileList()
{
    for(int i=0;i<m_fileInfoList.count();i++)
    {
       FileInfo* info= m_fileInfoList[i];
       //将图标设置进QListWidget中
       QIcon icon(":/res/file.jpg");
       QListWidgetItem* item1=new QListWidgetItem(icon,info->fileName);
       ui->listWidget->addItem(item1);
    }
}

//清除列表中的所有列表项
 void myfile::clearFileList()
 {

     //删除文件列
     int count=m_fileInfoList.count();
     for(int i=0;i<count;i++)
     {
         FileInfo* info=m_fileInfoList.front();
         m_fileInfoList.pop_front();
         delete info;
     }

 }
void myfile::clearFileItem()
{
    int count=ui->listWidget->count();
    for(int i=0;i<count;i++)
    {
        QListWidgetItem* item=ui->listWidget->takeItem(0);
        delete item;
    }
}

void myfile::myfileInit()
{
    //设置图标模式
    ui->listWidget->setViewMode(QListView::IconMode);
    //设置在窗口中图片的大小
    ui->listWidget->setIconSize(QSize(80,80));
    //设置布局的大小
    ui->listWidget->setGridSize(QSize(100,200));

    //自适应布局，需要将窗口进行布局才能生效
    ui->listWidget->setResizeMode(QListView::Adjust);
    //设置图标拖动状态，QListView::Static表示不可以拖动
    ui->listWidget->setMovement(QListView::Static);
}

void myfile::dealfile(DealFile cmd)
{
    //选中当前鼠标的item
    QListWidgetItem* item=ui->listWidget->currentItem();

    for(int i=0;i<m_fileInfoList.length();i++)
    {
        FileInfo* fileInfo=m_fileInfoList[i];
        if(fileInfo->fileName==item->text())
        {
            if(cmd==DealFile::Share)
            {
                //分享文件
                 shareFile(fileInfo);
            }
            else if(cmd==DealFile::Delete)
            {
                //删除文件
                deleteFile(fileInfo);
            }
            else if(cmd==DealFile::Show)
            {
                //显示文件属性
                showFileProperty(fileInfo);
            }
            else if(cmd==DealFile::Download)
            {
                //下载文件

            }
        }
    }
}


void myfile::showFileProperty(FileInfo *fileInfo)
{
    //弹出对话框，显示文件属性
    filePropertyiInfoDialog* dialog=new filePropertyiInfoDialog();
    dialog->setFileInfo(fileInfo);
    dialog->show();
}


void myfile::shareFile(FileInfo *fileInfo)
{

}
void myfile::deleteFile(FileInfo *fileInfo)
{

}

void myfile::uploadFile()
{

}


myfile::~myfile()
{
    delete ui;
}
