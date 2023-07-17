#include "dialog.h"
#include "ui_dialog.h"
#include<QPainter>
#include"common.h"
#include<QRegExp>
#include<QMessageBox>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include"des.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    mainwindow=new MainWindow();


    ui->setupUi(this);
    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //设置所有的字体的格式
    setFont(QFont("楷体",12,QFont::Bold,false));
    ui->stackedWidget->setCurrentWidget(ui->login_page);
    connect(ui->widget,&titleWidget::switchSettingPage,this,&Dialog::switchSettingPage);
    connect(ui->widget,&titleWidget::hidePage,this,&Dialog::hidePage);
    connect(ui->widget,&titleWidget::closePage,this,&Dialog::closePage);
    connect(mainwindow,&MainWindow::switchUser,this,[=](){
        mainwindow->hide();
        this->show();
    });
  //  connect(ui->reg_but,&QToolButton::clicked,this,&Dialog::on_toolButton_3_clicked);
    m_common=Common::getInstant();

    readConf();
    qDebug()<<"加载文件成功";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::hidePage()
{
    //最小化窗口
   this->setWindowState(Qt::WindowMinimized);
}

void Dialog::closePage()
{
  close();
}

void Dialog::paintEvent(QPaintEvent*)
{
    QPainter* painter=new QPainter(this);
    QPixmap pixmap;
    pixmap.load(":/res/login_bk.jpg");
    painter->drawPixmap(0,0,this->width(),this->height(),pixmap);
    painter->end();
}

void Dialog::on_register_toolButton_clicked()
{
    //显示注册页
    //setCurrentWidget设置当前页面
    ui->stackedWidget->setCurrentWidget(ui->register_page);
}

void Dialog::on_toolButton_4_clicked()
{
    //显示登录页
    ui->stackedWidget->setCurrentWidget(ui->login_page);
}

 void Dialog::switchSettingPage()
 {
     //切换到设置页
     ui->stackedWidget->setCurrentWidget(ui->set_page);
 }

void Dialog::on_toolButton_clicked()
{
    //显示登录页
    ui->stackedWidget->setCurrentWidget(ui->login_page);
}

//登录按钮
void Dialog::on_login_toolButton_clicked()
{
    qDebug()<<"登录";
    //获取账号密码
    QString account=ui->account_edit->text();
    QString password=ui->password_edit->text();

    //
    QRegExp reg(USER_REG);

    //校验账号的规则
    if(!reg.exactMatch(account))
    {
        //校验失败
        QMessageBox::warning(this,"警告","输入的账号格式有误");
        return;
    }

    reg.setPattern(PASSWD_REG);

    if(!reg.exactMatch(password)){
        QMessageBox::warning(this,"警告","输入的密码格式有误");
        return;
    }

    //
    QNetworkAccessManager* manger=new QNetworkAccessManager();
    //封装http请求
    QNetworkRequest request;
    //从配置文件中获取到ip地址和port端口号
    QString ip=Common::getInstant()->getConfValue("web_server","ip");
    QString port=Common::getInstant()->getConfValue("web_server","port");
    QString url=QString("http://%1:%2/login").arg(ip).arg(port);//设置登录的url
    request.setUrl(QUrl(url));

    //设置文件类型
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    //将data数据以QJson的格式发送给服务器

    QJsonObject object;
    object.insert("account", account);
    object.insert("password",  m_common->getStrMd5(password));

    QJsonDocument doc(object);
    QByteArray data=doc.toJson();
    //发送数据
    QNetworkReply* rely=manger->post(request,data);
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
        if(value1=="000"){

            //登录成功
            //1.判断有没有记住密码，如果有记住密码，获取记住密码的状态
            //2.将账号和密码信息记录到配置文件中
            //3.显示登录成功页面（主页面）


          //  QMessageBox::information(this,"登录成功","账号登录成功");
            //判断有没有记住密码

            bool checkBox=ui->rember_checkBox->isChecked();
            if(checkBox==false)
            {
                //没有记住密码直接清除密码框
                ui->password_edit->clear();
            }

            //将账号密码保存到配置文件中
            m_common->writeLoginInfo(account,password,checkBox);
            //获取

            //显示主页面
            mainwindow->setUser(account);
            mainwindow->show();
            this->hide();
        }

        if(value1=="001"){
            QMessageBox::warning(this,"警告","登录");
        }
    });

}



//读取配置文件信息，将账号密码，服务器端口号写到界面中
 void Dialog::readConf()
 {
     QString user_base64=m_common->getConfValue("login","user");
     QString pwd_base64=m_common->getConfValue("login","pwd");
     QString remember=m_common->getConfValue("login","remember");

     //对账号进行base64解密和desc解密
     QByteArray usr_des=QByteArray::fromBase64(user_base64.toLocal8Bit());
     unsigned char usr[1024]={0};
     int usr_len;
     //进行desc解密
     if(DesDec((unsigned char*)usr_des.data(),usr_des.length(),usr,&usr_len)!=0){
         qDebug()<<"desc解密失败";
     }

     //账号解密成功，将账号显示到登录窗口
     QString s=QString::fromLocal8Bit((const char*)usr,usr_len);
     ui->account_edit->setText(s);

     if(remember=="yes")
     {
         ui->rember_checkBox->setCheckState(Qt::Checked);
         //记住密码，将密码显示到密码框上
         QByteArray pwd_des=QByteArray::fromBase64(pwd_base64.toLocal8Bit());
         unsigned char pwd[1024]={0};
         int pwd_len=0;
         //进行desc解密
         if(DesDec((unsigned char*)pwd_des.data(),usr_des.length(),pwd,&pwd_len)!=0){
             qDebug()<<"密码解密失败";
         }

         //账号解密成功，将账号显示到登录窗口
         QString s1=QString::fromLocal8Bit((const char*)pwd,pwd_len);
         ui->password_edit->setText(s1);
     }


    //将ip地址和端口号显示到服务器设置页面
     QString ip=m_common->getConfValue("web_server","ip");
     QString port=m_common->getConfValue("web_server","port");


     ui->ip_edit->setText(ip);
     ui->port_eidt->setText(port);
 }

 //点击服务器设置页的按钮，将ip地址和端口写入到配置文件中
void Dialog::on_ok_button_clicked()
{
    qDebug()<<"设置";
    QString ip=ui->ip_edit->text();
    QString port=ui->port_eidt->text();

    QRegExp reg(IP_REG);
    //校验账号的规则
    if(!reg.exactMatch(ip))
    {
        //校验失败
        QMessageBox::warning(this,"警告","输入的IP地址有误");
        return;
    }

     reg.setPattern(PORT_REG);
    //校验账号的规则
    if(!reg.exactMatch(port))
    {
        //校验失败
        QMessageBox::warning(this,"警告","输入的端口号有误");
        return;
    }

    m_common->writeWebInfo(ip,port);
    return;
}


//注册框的流程
void Dialog::on_reg_but_clicked()
{

        qDebug()<<"注册";
        /*
          1.获取输入框中的数据
          2.校验数据格式是否正确
          3.封装http请求，发送http请求
          4.接收http响应，处理http响应
        */
        QString usr=ui->usr_edit->text();
        QString nickname=ui->nickname_edit->text();
        QString password=ui->pasword_edit2->text();
        QString confirmpassword=ui->confirm_edit->text();
        QString mail=ui->mailbox_edit->text();
        QString phone=ui->phone_edit->text();


        qDebug()<<usr;
        QRegExp reg(USER_REG);

        //校验账号的规则
        if(!reg.exactMatch(usr))
        {
            //校验失败
            QMessageBox::warning(this,"警告","输入的账号格式有误");
            return;
        }

        reg.setPattern(PASSWD_REG);

        if(!reg.exactMatch(password)){
            QMessageBox::warning(this,"警告","输入的密码格式有误");
            return;
        }

        reg.setPattern(EMAIL_REG);

        if(!reg.exactMatch(mail)){
            QMessageBox::warning(this,"警告","输入的邮箱格式有误");
            return;
        }

        reg.setPattern(PHONE_REG);

        if(!reg.exactMatch(phone)){
            QMessageBox::warning(this,"警告","输入的手机号码格式有误");
            return;
        }

        if(confirmpassword!=password){
            QMessageBox::warning(this,"警告","确认密码不匹配");
            return;
        }

        //
        QNetworkAccessManager* manger=new QNetworkAccessManager();
        //封装http请求
        QNetworkRequest request;
        //从配置文件中获取到ip地址和port端口号
        QString ip=Common::getInstant()->getConfValue("web_server","ip");
        QString port=Common::getInstant()->getConfValue("web_server","port");
        QString url=QString("http://%1:%2/register").arg(ip).arg(port);
        request.setUrl(QUrl(url));

        //设置文件类型
        request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
        //将data数据以QJson的格式发送给服务器

        QJsonObject object;
        object.insert("email", mail);//邮箱
        object.insert("userName", usr);//账号
        object.insert("phone", phone);
        object.insert("nickName", nickname);

        object.insert("firstPwd", m_common->getStrMd5(password));
        QJsonDocument doc(object);

        QByteArray data=doc.toJson();
        qDebug()<<data;
        //发送数据
        QNetworkReply* rely=manger->post(request,data);
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
            if(value1=="002"){
                QMessageBox::information(this,"注册成功","账号注册成功");
            }

            if(value1=="003"){
                QMessageBox::warning(this,"警告","该账号已经存在");
            }

            if(value1=="004"){
                QMessageBox::critical(this,"注册失败","注册失败");
            }
       });
}
