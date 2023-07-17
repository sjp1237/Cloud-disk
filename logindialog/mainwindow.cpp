#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"
#include"buttongroup.h"
#include<QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    connect(ui->butgroup,&buttongroup::hideWidget,this,&MainWindow::hideWidget);
    connect(ui->butgroup,&buttongroup::closeWidget,this,&MainWindow::closeWidget);


    ui->stackedWidget->setCurrentWidget(ui->myfile_page);

     setSiganlButton();
}


void MainWindow::setSiganlButton()
{
    //切换到我的文件页面
    connect(ui->butgroup,&buttongroup::myfilePage,this,[=](){

        ui->stackedWidget->setCurrentWidget(ui->myfile_page);
    });

    //切换到共享页面
    connect(ui->butgroup,&buttongroup::sharePage,this,[=](){
         ui->stackedWidget->setCurrentWidget(ui->share_page);
    });

    //切换到下载页面
    connect(ui->butgroup,&buttongroup::loadPage,this,[=](){
         ui->stackedWidget->setCurrentWidget(ui->load_page);
    });

    //传输列表页面
    connect(ui->butgroup,&buttongroup::tranPage,this,[=](){
         ui->stackedWidget->setCurrentWidget(ui->tran_page);
    });

    //切换用户页面
    connect(ui->butgroup,&buttongroup::switchPage,this,[=](){
         emit switchUser();

    });

    //切换到用户页面
    connect(ui->butgroup,&buttongroup::userPage,this,[=](){

         ui->stackedWidget->setCurrentWidget(ui->user_page);
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter* painter=new QPainter(this);
    QPixmap pixmap;
    pixmap.load(":/res/bk_page.png");
    painter->drawPixmap(0,0,this->width(),this->height(),pixmap);
    painter->end();
}


void MainWindow::hideWidget()
{
    this->setWindowState(Qt::WindowMinimized);
}
void MainWindow::closeWidget()
{
    this->close();
}


 void MainWindow::setUser(QString name)
 {
     ui->butgroup->setUserName(name);
 }

