#include "buttongroup.h"
#include "ui_buttongroup.h"

buttongroup::buttongroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buttongroup)
{
    ui->setupUi(this);
    ui->myfile_btn->setStyleSheet("color:white");
}

buttongroup::~buttongroup()
{
    delete ui;
}

//最小化按钮
void buttongroup::on_toolButton_8_clicked()
{

}

//我的文件按钮
void buttongroup::on_myfile_btn_clicked()
{
   ui->user_btn->setStyleSheet("color:black");
   ui->load_btn->setStyleSheet("color:black");
   ui->share_btn->setStyleSheet("color:black");
   ui->myfile_btn->setStyleSheet("color:white");
   ui->tran_btn->setStyleSheet("color:black");
   ui->switch_btn->setStyleSheet("color:black");
   ui->user_btn->setStyleSheet("color:black");
    emit myfilePage();
}

//分享文件按钮
void buttongroup::on_share_btn_clicked()
{
     ui->user_btn->setStyleSheet("color:black");
    ui->load_btn->setStyleSheet("color:black");
    ui->share_btn->setStyleSheet("color:white");
    ui->myfile_btn->setStyleSheet("color:black");
    ui->tran_btn->setStyleSheet("color:black");
    ui->switch_btn->setStyleSheet("color:black");
    ui->user_btn->setStyleSheet("color:black");
    emit sharePage();
}

//下载榜按钮
void buttongroup::on_load_btn_clicked()
{
     ui->user_btn->setStyleSheet("color:black");
    ui->load_btn->setStyleSheet("color:white");
    ui->share_btn->setStyleSheet("color:black");
    ui->myfile_btn->setStyleSheet("color:black");
    ui->tran_btn->setStyleSheet("color:black");
    ui->switch_btn->setStyleSheet("color:black");
    emit loadPage();
}

//传输列表
void buttongroup::on_tran_btn_clicked()
{
    ui->user_btn->setStyleSheet("color:black");
    ui->load_btn->setStyleSheet("color:black");
    ui->share_btn->setStyleSheet("color:black");
    ui->myfile_btn->setStyleSheet("color:black");
    ui->tran_btn->setStyleSheet("color:white");
    ui->switch_btn->setStyleSheet("color:black");
    emit tranPage();
}

//切换用户按钮
void buttongroup::on_switch_btn_clicked()
{
    emit switchPage();
}

void buttongroup::on_user_btn_clicked()
{
    ui->user_btn->setStyleSheet("color:white");
    ui->load_btn->setStyleSheet("color:black");
    ui->share_btn->setStyleSheet("color:black");
    ui->myfile_btn->setStyleSheet("color:black");
    ui->tran_btn->setStyleSheet("color:black");
    ui->switch_btn->setStyleSheet("color:black");
    emit userPage();
}



//隐藏窗口
void buttongroup::on_hide_but1_clicked()
{

    emit hideWidget();
}

//关闭窗口
void buttongroup::on_close_but_1_clicked()
{
    emit closeWidget();
}

void buttongroup::setUserName(QString name)
{
    ui->user_btn->setText(name);
}

