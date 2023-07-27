#include "sharefilewidget.h"
#include "ui_sharefilewidget.h"
#include"mymenu.h"
#include"filepropertyiinfodialog.h"
#include<QNetworkReply>
#include<QMessageBox>
#include<QFileDialog>
ShareFileWidget::ShareFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShareFileWidget)
{
    ui->setupUi(this);
     m_logininfo=logininfoinstance::getInstant(); //登录信息
    m_manager=Common::getInstant()->getNetworkManger(); //http管理
    m_downloadtask=downloadtask::getInstant();
    ShareFileWidgetInit();
    setWidgetMemu();//设置菜单栏
    setMenuAction();//设置菜单栏选项
}



ShareFileWidget::~ShareFileWidget()
{
    delete ui;
}


void ShareFileWidget::setWidgetMemu()
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


//显示文件列表到QListWidget
void ShareFileWidget::refreshFileList()
{
    for(int i=0;i<m_fileInfoList.count();i++)
    {
       FileInfo* info= m_fileInfoList[i];
       //将图标设置进QListWidget中
        QIcon icon(":/res/txt.png");
       if(info->type=="jpg"||info->type=="png")
       {
           icon.addFile(":/res/jpg.png");
       }else if(info->type=="pdf")
       {
           icon.addFile(":/res/pdf.png");
       }

       QListWidgetItem* item1=new QListWidgetItem(icon,info->fileName);
       item1->setTextAlignment(Qt::AlignLeft);
       ui->listWidget->addItem(item1);
    }
}


void ShareFileWidget::ShareFileWidgetInit()
{
    //设置图标模式
    ui->listWidget->setViewMode(QListView::IconMode);
    //设置在窗口中图片的大小
    ui->listWidget->setIconSize(QSize(80,80));
    //设置布局的大小
    ui->listWidget->setGridSize(QSize(120,200));

    //自适应布局，需要将窗口进行布局才能生效
    ui->listWidget->setResizeMode(QListView::Adjust);
    //设置图标拖动状态，QListView::Static表示不可以拖动
    ui->listWidget->setMovement(QListView::Static);
}


void ShareFileWidget::showFileProperty(FileInfo *fileInfo)
{
    //弹出对话框，显示文件属性
    filePropertyiInfoDialog* dialog=new filePropertyiInfoDialog();
    dialog->setFileInfo(fileInfo);
    dialog->show();
}


void ShareFileWidget::setMenuAction()
{
    m_downloadAction=new QAction("下载");
    m_saveAction=new QAction("保存文件");
    m_CancelShareAction=new QAction("取消分享");   //分享
    m_propertyAction=new QAction("属性");//属性


    m_fileMenu->addAction(m_downloadAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_saveAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_CancelShareAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_propertyAction);

    //右键点击空白产生的菜单
    m_refreshAction=new QAction("更新");      //更新
    m_blankMenu->addAction(m_refreshAction);

    //给菜单选项设置槽函数
    setActionConnect();
}


void ShareFileWidget::setActionConnect()
{
    //右键文件菜单
    //点击下载文件
    connect(m_downloadAction,&QAction::triggered,this,[=]{
         dealfile(DealFile::Download);
    });

    //点击删除文件
    connect(m_saveAction,&QAction::triggered,this,[=]{
         dealfile(DealFile::Save);
    });

    //点击取消分享文件
    connect(m_CancelShareAction,&QAction::triggered,this,[=]{
         dealfile(DealFile::CancelShare);
    });

    //点击文件属性
    connect(m_propertyAction,&QAction::triggered,this,[=]{
        qDebug()<<"显示文件属性";
        dealfile(DealFile::Show);
    });


    //右键空白菜单栏
    connect(m_refreshAction,&QAction::triggered,this,[=]{
            getFileCount();
            qDebug()<<"更新";
    });

}



void ShareFileWidget::addDownloadFile(FileInfo *fileInfo)
{
    //添加上传文件
    //获取文件保存路径，并打开该文件+并判断该路径是否合法
    QString filePath=QFileDialog::getSaveFileName(this,"请选择路径",fileInfo->fileName);

    //int appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask);
    qDebug()<<filePath;
    m_downloadtask->appendDownloadTask(fileInfo,filePath);
}




void ShareFileWidget::dealfile(DealFile cmd)
{
    //选中当前鼠标的item
    QListWidgetItem* item=ui->listWidget->currentItem();

    for(int i=0;i<m_fileInfoList.length();i++)
    {
        FileInfo* fileInfo=m_fileInfoList[i];
        if(fileInfo->fileName==item->text())
        {
            if(cmd==DealFile::CancelShare)
            {
                cancelShareFile(fileInfo);
                qDebug()<<"取消分享文件";
            }
            else if(cmd==DealFile::Save)
            {
                //保存文件
                saveFile(fileInfo);
                qDebug()<<"保存文件";
            }
            else if(cmd==DealFile::Show)
            {
                //显示文件属性
                showFileProperty(fileInfo);
                 qDebug()<<"显示文件属性";
            }
            else if(cmd==DealFile::Download)
            {
                //下载文件
                addDownloadFile(fileInfo);
               qDebug()<<"下载文件";
            }
        }
    }
}

//http://192.168.52.139/dealsharefile?cmd=cancel

/*
{
    "filename": "ui_buttongroup.h",
    "md5": "a89390d867d5da18c8b1a95908d7c653",
    "user": "sjp" //用户,不是文件所属的用户
}
*/

void ShareFileWidget::cancelShareFile(FileInfo *fileInfo)
{
    //封装http请求
    QNetworkRequest request;
    //从配置文件中获取到ip地址和port端口号
    QString ip=Common::getInstant()->getConfValue("web_server","ip");
    QString port=Common::getInstant()->getConfValue("web_server","port");
    QString url = QString("http://%1:%2/dealsharefile?cmd=cancel").arg(ip).arg(port);

    request.setUrl(QUrl(url));

    QJsonObject object;
    object.insert("filename", fileInfo->fileName);
    object.insert("user", logininfoinstance::getInstant()->user());
    object.insert("md5", fileInfo->md5);

    QJsonDocument doc(object);
    QByteArray data=doc.toJson();
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));

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
        /*
         * 020:成功
         * 021：文件已经存在
         * 022：失败
         *
         * */
        if(value1=="018"){
            QMessageBox::information(this,"提示","取消分享文件成功");
            getFileCount();
        }
        if(value1=="019"){
             QMessageBox::warning(this,"提示","取消失败，你不是该文件的所属用户");
        }
         rely->deleteLater();
    });
}

/*
 *
 * http://192.168.52.139/dealsharefile?cmd=save
{
    "filename": "ui_buttongroup.h",
    "md5": "a89390d867d5da18c8b1a95908d7c653",
    "user": "sjp"
}
*/
 void ShareFileWidget::saveFile(FileInfo* fileInfo)
 {
     //封装http请求
     QNetworkRequest request;
     //从配置文件中获取到ip地址和port端口号
     QString ip=Common::getInstant()->getConfValue("web_server","ip");
     QString port=Common::getInstant()->getConfValue("web_server","port");
     QString url = QString("http://%1:%2/dealsharefile?cmd=save").arg(ip).arg(port);

     request.setUrl(QUrl(url));

     QJsonObject object;
     object.insert("filename", fileInfo->fileName);
     object.insert("user", logininfoinstance::getInstant()->user());
     object.insert("md5", fileInfo->md5);

     QJsonDocument doc(object);
     QByteArray data=doc.toJson();
     request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));

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
         /*
          * 020:成功
          * 021：文件已经存在
          * 022：失败
          *
          * */
         if(value1=="020"){
             QMessageBox::information(this,"提示","保存成功");
         }
         if(value1=="021"){
              QMessageBox::information(this,"提示","文件已经存在");
         }
         if(value1=="022")
         {
          QMessageBox::information(this,"提示","失败");
         }
          rely->deleteLater();
     });
 }





//http://119.23.41.13/sharefiles?cmd=count
//获取文件数量
void ShareFileWidget::getFileCount()
{
    //封装http请求
    QNetworkRequest request;
    //从配置文件中获取到ip地址和port端口号
    QString ip=Common::getInstant()->getConfValue("web_server","ip");
    QString port=Common::getInstant()->getConfValue("web_server","port");
    QString url = QString("http://%1:%2/sharefiles?cmd=count").arg(ip).arg(port);

    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));

    QNetworkReply* rely=m_manager->get(request);

    connect(rely,&QNetworkReply::readyRead,this,[=]{
        //响应到达,读取所有的数据
        QByteArray s=rely->readAll();
        m_sharefileCount=s.toInt()+1;
        if(m_sharefileCount>=0){

          getFileList();
        }
        else {
            clearFileList();
            clearFileItem();
        }
         rely->deleteLater();
    });
}

void ShareFileWidget::getFileList()
{
    //封装http请求
    QNetworkRequest request;
    //从配置文件中获取到ip地址和port端口号
    QString ip=Common::getInstant()->getConfValue("web_server","ip");
    QString port=Common::getInstant()->getConfValue("web_server","port");

    //http://192.168.52.139/sharefiles?cmd=normal
    QString url = QString("http://%1:%2/sharefiles?cmd=normal").arg(ip).arg(port);
    qDebug()<<url;
    request.setUrl(QUrl(url));

    //设置数据类型
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    //将data数据以QJson的格式发送给服务器

    QJsonObject object;
    object.insert("user", m_logininfo->user());
    object.insert("token", m_logininfo->token());
    object.insert("start", 0);
    object.insert("count", m_sharefileCount);

    QJsonDocument doc(object);
    QByteArray data=doc.toJson();
    //发送请求
    QNetworkReply* rely=m_manager->post(request,data);

    connect(rely,&QNetworkReply::readyRead,this,[=]{

        //响应到达,读取所有的数据
        QByteArray s=rely->readAll();
        clearFileList();
        clearFileItem();
        AnalyJsonData::getFileList(s,m_fileInfoList);
        refreshFileList();
        rely->deleteLater();
    });
}


//清除列表中的所有列表项
 void ShareFileWidget::clearFileList()
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


void ShareFileWidget::clearFileItem()
{
    int count=ui->listWidget->count();
    for(int i=0;i<count;i++)
    {
        QListWidgetItem* item=ui->listWidget->takeItem(0);
        delete item;
    }
}




