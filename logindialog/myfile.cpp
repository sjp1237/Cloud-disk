#include "myfile.h"
#include "ui_myfile.h"
#include"mymenu.h"
#include<QDebug>
#include<QFileDialog>
#include<QMessageBox>
#include"common.h"
#include"filepropertyiinfodialog.h"
#include"logininfoinstance.h"


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

    getFileCount(Normal);//获取文件列表
    checkTaskList();
}

void myfile::checkTaskList()
{
    m_uploadTimer.start(500);
    connect(&m_uploadTimer,&QTimer::timeout,this,[=]()
    {
        uploadFileAction();
    });

    m_downloadTimer.start(500);
    connect(&m_downloadTimer,&QTimer::timeout,this,[=]()
    {
        DownloadFileAction();
    });
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
             addUploadFile();
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
           // qDebug()<<"myfileCount："<<myfileCount;
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
    QIcon icon(":/res/111111.png");
    QListWidgetItem* item1=new QListWidgetItem(icon,"上传文件");
    ui->listWidget->addItem(item1);
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
    m_uploadtask=new uploadtask;
    m_downloadtask=new downloadtask;
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

    connect(ui->listWidget,&QListWidget::itemDoubleClicked,this,[=](QListWidgetItem *item){
        if(item->text()=="上传文件")
        {
            addUploadFile();
        }
    });
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
                addDownloadFile(fileInfo);
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



//快传文件的http请求
/*
 * http://119.23.41.13:8081/md5
 *{
        "fileName": "ui_buttongroup.h",
        "md5": "a89390d867d5da18c8b1a95908d7c653",
        "token": "ecf3ac6f8863cd17ed1d3909c4386684",
        "user": "sjp"
 * }
 *
 * */
void myfile::uploadFileAction()
{
    if(m_uploadtask->isEmpty()){
        //任务列表为空
        // qDebug()<<"任务列表为空";
        return;
    }
    UploadFileInfo* uploadFileInfo=m_uploadtask->takeTask();
    //先进行快传，判断文件是否已经上传成功
    //封装http请求

    //如果该文件没有上传，则发送请求
    if(uploadFileInfo->uploadStatus==UPLOAD_NOT)
    {
        uploadFileInfo->uploadStatus=UPLOADING;
        QNetworkRequest request;
        //从配置文件中获取到ip地址和port端口号
        QString ip=Common::getInstant()->getConfValue("web_server","ip");
        QString port=Common::getInstant()->getConfValue("web_server","port");
        QString url = QString("http://%1:%2/md5").arg(ip).arg(port);
        request.setUrl(QUrl(url));

        //设置文件类型
        request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
        //将data数据以QJson的格式发送给服务器

        QJsonObject object;
        object.insert("user", m_logininfo->user());
        object.insert("token", m_logininfo->token());
        object.insert("md5",uploadFileInfo->md5);
        object.insert("fileName",uploadFileInfo->fileName);

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
            if(value1=="005"){

                qDebug()<<"文件已经存在";
                //文件正在上传
                uploadFileInfo->uploadStatus=UPLOAF_FILE_EXISTE;
                m_uploadtask->delUploadTask();
                 Common::getInstant()->writeRecord(m_logininfo->user(),uploadFileInfo->fileName,value1);
                return;
            }
            if(value1=="006"){
                uploadFileInfo->uploadStatus=UPLOAF_FILE_EXISTE;
                m_uploadtask->delUploadTask();
                 Common::getInstant()->writeRecord(m_logininfo->user(),uploadFileInfo->fileName,value1);
                qDebug()<<"妙传成功";
            }

            if(value1=="007"){
                //qDebug()<<"上传文件";
                //文件没有上传到服务器上，需要将文件上传到服务器上
                uploadFile(uploadFileInfo);

            }

            if(value1=="111")
            {
                Common::getInstant()->writeRecord(m_logininfo->user(),uploadFileInfo->fileName,value1);
                qDebug()<<"token验证失败";
            }
        });
    }

}

void myfile::addUploadFile()
{
    //添加上传文件
    QStringList filelist=QFileDialog::getOpenFileNames();

    for(int i=0;i<filelist.size();i++)
    {
        int res=m_uploadtask->appendUploadTask(filelist[0]);
        if(res==-1){
            QMessageBox::warning(this,"警告","文件大小大于30m");
        }
    }
}


//将文件上传到服务器上
/*
------WebKitFormBoundaryDQAR0QX1ojAyzAre\r\n
Content-Disposition: form-data; name="file"; filename="logo.png"\r\n
Content-Type: image/png\r\n
\r\n
真正的文件内容\r\n
------WebKitFormBoundaryDQAR0QX1ojAyzAre
*/
//将文件内容上传到服务器上
void myfile::uploadFile(UploadFileInfo *uploadFileInfo)
{

        QFile file(uploadFileInfo->filePath);
        file.open(QIODevice::ReadOnly | QIODevice::Text);

        logininfoinstance *login = logininfoinstance::getInstant();

        QString boundary = m_common->getBoundary();
        QByteArray data;
        data.append(boundary);
        data.append("\r\n");

        data.append("Content-Disposition: form-data; ");
        data.append(QString("user=\"%1\" filename=\"%2\" md5=\"%3\" size=%4")
                    .arg(login->user())
                    .arg(uploadFileInfo->fileName)
                    .arg(uploadFileInfo->md5)
                    .arg(uploadFileInfo->size));
        data.append("\r\n");
        data.append("Content-Type: application/octet-stream");
        data.append("\r\n");
        data.append("\r\n");


        //上传文件
        data.append(file.readAll());
        data.append("\r\n");
        data.append(boundary);

        if (file.isOpen()) {
            file.close();
        }

        QString url = QString("http://%1:%2/upload").arg(login->ip()).arg(login->port());
        QNetworkRequest request;
        request.setUrl(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

        //发送http请求
        QNetworkReply *reply = m_manager->post(request, data);
        if (reply == NULL) {
            qDebug() << "请求失败";
            return;
        }


        //显示文件上传进度
        connect(reply, &QNetworkReply::uploadProgress, this, [=](qint64 bytesSent, qint64 bytesTotal){
            //bytesSent 上传的字节数
            //bytesTotal 文件需要上传的总字节数

           if (bytesTotal != 0) {
                //显示进度条(设置进度条)
             uploadFileInfo->fdp->setValue(bytesSent, bytesTotal);
           }

        });

        connect(reply, &QNetworkReply::finished, this, [=](){
            //文件上传完成后
            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << reply->errorString();
            } else {
                QByteArray s=reply->readAll();

    /*
    008: 上传成功
    009: 上传失败
    */
                //响应到达,读取所有的数据

                // qDebug() << "服务器返回数据:" << QString(s);
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

                if (value1== "008") {

                    qDebug() << "上传成功";
                    uploadFileInfo->uploadStatus=UPLOAD_FINISHED;
                    getFileCount(Normal);


                } else if (value1 == "009") {

                    uploadFileInfo->uploadStatus=UPLOAD_FAILD;
                    qDebug() << "上传失败";
                }
                //将传输记录记录到文件中
                Common::getInstant()->writeRecord(login->user(),uploadFileInfo->fileName,value1);
              //   writeRecord(QString user, QString fileName, QString code, QString path)
            }
            m_uploadtask->delUploadTask();
            reply->deleteLater();
        });
}

void myfile::addDownloadFile(FileInfo *fileInfo)
{
    //添加上传文件
    //获取文件保存路径，并打开该文件+并判断该路径是否合法
    QString filePath=QFileDialog::getSaveFileName(this,"请选择路径",fileInfo->fileName);

    //int appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask);
    qDebug()<<filePath;
    m_downloadtask->appendDownloadTask(fileInfo,filePath);
}

void myfile::DownloadFileAction()
{
    if(m_downloadtask->isEmpty()){
        //任务列表为空
        // qDebug()<<"任务列表为空";
        return;
    }

    DownloadFileInfo* downloadFileInfo=m_downloadtask->takeTask();

    //判断任务是否正在下载
    if(downloadFileInfo->status==DOWNLOAD_NOT)
    {
        downloadFileInfo->status=DOWNLOADING;
        //先进行快传，判断文件是否已经上传成功
        //封装http请求
        QNetworkRequest request;
        //文件的url: http://172.31.39.20:80/group1/M00/00/00/rB8nFGS9n5KAdiyYADNSzTgsyJg344.doc
        //172.31.39.20是云服务器上的私网ip，客户端是访问不进去d
        //119.23.41.13是云服务器上的公网ip
        //需要将119.23.41.13替换172.31.39.20

        downloadFileInfo->url.replace(7,12,"119.23.41.13");
        qDebug()<<downloadFileInfo->url;
        request.setUrl(QUrl(downloadFileInfo->url));
        QNetworkReply* rely=m_manager->get(request);

         connect(rely,&QNetworkReply::readyRead,this,[=](){
             //读取数据
             QByteArray data=rely->readAll();
             downloadFileInfo->file->write(data);
         });

         connect(rely,&QNetworkReply::finished,this,[=](){
             //读取成功，删除下载任务
             m_downloadtask->delUploadTask();
         });

         connect(rely,&QNetworkReply::downloadProgress,this,[=](int recvSize,int totalSize){
             if(totalSize!=0){
                 downloadFileInfo->fdp->setValue(recvSize,totalSize);
             }
         });
    }
}

void myfile::DownloadFile(UploadFileInfo *uploadFileInfo)
{

}

void myfile::shareFile(FileInfo *fileInfo)
{

}
void myfile::deleteFile(FileInfo *fileInfo)
{

}




myfile::~myfile()
{
    delete ui;
}
