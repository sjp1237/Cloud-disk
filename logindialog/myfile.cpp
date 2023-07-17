#include "myfile.h"
#include "ui_myfile.h"
#include"mymenu.h"
#include<QDebug>
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
    connect(m_downloadAction,&QAction::triggered,this,[=]{

    });

    connect(m_deleteAction,&QAction::triggered,this,[=]{

    });

    connect(m_shareAction,&QAction::triggered,this,[=]{

    });

    connect(m_propertyAction,&QAction::triggered,this,[=]{

    });

    //右键空白菜单
    connect(m_downloadAscAction,&QAction::triggered,this,[=]{
              qDebug()<<"按下载量降序";
    });


    connect(m_downloadDescAction,&QAction::triggered,this,[=]{
              qDebug()<<"按下载量升序";
    });

    connect(m_refreshAction,&QAction::triggered,this,[=]{
              qDebug()<<"更新";
    });

    connect(m_uploadAction,&QAction::triggered,this,[=]{
              qDebug()<<"上传";
    });


}
void myfile::myfileInit()
{
    //设置图标模式
    ui->listWidget->setViewMode(QListView::IconMode);
    //设置在窗口中图片的大小
    ui->listWidget->setIconSize(QSize(80,80));
    //设置布局的大小
    ui->listWidget->setGridSize(QSize(100,200));

    //将图标设置进QListWidget中
    QListWidgetItem* item1=new QListWidgetItem(QIcon(":/res/file.jpg"),"我的文件");
    ui->listWidget->addItem(item1);

    //自适应布局，需要将窗口进行布局才能生效
    ui->listWidget->setResizeMode(QListView::Adjust);
    //设置图标拖动状态，QListView::Static表示不可以拖动
    ui->listWidget->setMovement(QListView::Static);


}

//void myfile::myfileInit()
//{
//    m_common = Common::getInstance();
//    m_loginInfo = LoginInfoInstance::getInstance();

//    ui->listWidget->setViewMode(QListView::IconMode);
//    ui->listWidget->setIconSize(QSize(80,80));
//    ui->listWidget->setGridSize(QSize(100, 200));

//    ui->listWidget->addItem(new QListWidgetItem(QIcon("conf/fileType/jpg.png"), "图标1"));

//    //设置QListView大小改变时，图标的调整模式, 默认时固定的，可以改成自动调整
//    ui->listWidget->setResizeMode(QListView::Adjust); //自适应布局
//    //设置图标拖动状态，QListView::Static表示不可拖动
//    ui->listWidget->setMovement(QListView::Static);

//    //listWidget右键菜单
//    //发出QWidget::customContextMenuRequested() 信号
//    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(ui->listWidget, &QListWidget::customContextMenuRequested, this, &MyFileWidget::onRightMenu);
//}


myfile::~myfile()
{
    delete ui;
}
