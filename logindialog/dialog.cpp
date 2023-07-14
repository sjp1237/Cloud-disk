#include "dialog.h"
#include "ui_dialog.h"
#include<QPainter>
#include"common.h"
#include<QRegExp>
#include<QMessageBox>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //设置所有的字体的格式
    setFont(QFont("楷体",12,QFont::Bold,false));

    connect(ui->widget,&titleWidget::switchSettingPage,this,&Dialog::switchSettingPage);
    connect(ui->widget,&titleWidget::hidePage,this,&Dialog::hidePage);
    connect(ui->widget,&titleWidget::closePage,this,&Dialog::closePage);

    m_common=Common::getInstant();
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
    //获取账号密码
    QString account=ui->account_edit->text();
    QString passwd=ui->password_edit->text();

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

    if(!reg.exactMatch(passwd)){
        QMessageBox::warning(this,"警告","输入的密码格式有误");
        return;
    }


}

void Dialog::on_toolButton_3_clicked()
{
    /*
      1.获取输入框中的数据
      2.校验数据格式是否正确
      3.封装http请求，发送http请求
      4.
    */
    QString usr=ui->usr_edit->text();
    QString nickname=ui->nickname_edit->text();
    QString password=ui->pasword_edit2->text();
    QString confirmpassword=ui->confirm_edit->text();
    QString mail=ui->mailbox_edit->text();
    QString phone=ui->phone_edit->text();


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
    QByteArray data;
    QJsonObject object;
    object.insert("phone", phone);
    object.insert("userName", usr);
    object.insert("phone", phone);
    object.insert("nickName", nickname);

    object.insert("password", m_common->getStrMd5(password));
    QNetworkReply* rely=manger->post(request,data);

    connect(rely,&QNetworkReply::readyRead,this,[=]{

    });

}
