#include "dialog.h"
#include "ui_dialog.h"
#include<QPainter>
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
