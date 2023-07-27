#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"
#include"buttongroup.h"
#include<QPainter>

MainWindow* MainWindow::instant=nullptr;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    connect(ui->butgroup,&buttongroup::hideWidget,this,&MainWindow::hideWidget);
    connect(ui->butgroup,&buttongroup::closeWidget,this,&MainWindow::closeWidget);




     setSiganlButton();
}


void MainWindow::setSiganlButton()
{
    //切换到我的文件页面
    connect(ui->butgroup,&buttongroup::myfilePage,this,[=](){
        ui->stackedWidget->setCurrentWidget(ui->myfile_page);
        ui->myfile_page->showMyfile();
    });

    //切换到共享页面
    connect(ui->butgroup,&buttongroup::sharePage,this,[=](){
         ui->stackedWidget->setCurrentWidget(ui->share_page);
         ui->share_page->getFileCount();
    });


    //传输列表页面
    connect(ui->butgroup,&buttongroup::tranPage,this,[=](){
         ui->stackedWidget->setCurrentWidget(ui->tran_page);
    });

    //切换用户页面
    connect(ui->butgroup,&buttongroup::switchPage,this,[=](){
        //切换用户界面
         emit switchUser();
        //切换用户的所需要的操作
        ui->myfile_page->changerUser();
    });

}

void MainWindow::init()
{
      ui->stackedWidget->setCurrentWidget(ui->myfile_page);
      ui->myfile_page->showMyfile();
}
MainWindow *MainWindow::getinstant()
{
    //由于只有一个线程，可以不用加锁
    if(instant==nullptr){
        instant=new MainWindow;
    }
    return instant;
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

