#include "filepropertyiinfodialog.h"
#include "ui_filepropertyiinfodialog.h"
#include"analyjsondata.h"
filePropertyiInfoDialog::filePropertyiInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filePropertyiInfoDialog)
{
    ui->setupUi(this);
    QString style1 = QString("color: rgb(11, 11, 11);font: 75 14pt \"Agency FB\";");
    QString style2 = QString("font: 14pt \"隶书\";color: rgb(255, 156, 16);");

    this->setWindowTitle("文件属性");
    ui->lbl_fileName->setStyleSheet(style1);
    ui->lbl_fileSize->setStyleSheet(style1);
    ui->lbl_download->setStyleSheet(style1);
    ui->lbl_shareStatus->setStyleSheet(style1);
    ui->lbl_uploadTime->setStyleSheet(style1);
    ui->lbl_uploadUser->setStyleSheet(style1);
    ui->lbl_pv->setStyleSheet(style1);

    ui->val_fileName->setStyleSheet(style2);
    ui->val_fileSize->setStyleSheet(style2);
    ui->val_download->setStyleSheet(style2);
    ui->val_shareStatus->setStyleSheet(style2);
    ui->val_uploadTime->setStyleSheet(style2);
    ui->val_uploadUser->setStyleSheet(style2);
    ui->val_pv->setStyleSheet(style2);
}

void filePropertyiInfoDialog::setFileInfo(FileInfo *fileInfo)
{
    ui->val_fileName->setText(fileInfo->fileName);

    int size=fileInfo->size;
    QString fileSize;
    if(size<1024){
          fileSize=QString("%1字节").arg(QString::number(size));
    }
    else if(size>=1024)
    {
         fileSize=QString("%1 kb").arg(QString::number(size/1024));
    }
    else if(size>=1024*1024)
    {
          fileSize=QString("%1 kb").arg(QString::number(size/(1024*1024)));
    }
    ui->val_fileSize->setText(fileSize);
    ui->val_download->setText(fileInfo->url);

    ui->val_shareStatus->setText(QString::number(fileInfo->shareStatus));
    ui->val_uploadTime->setText(fileInfo->createTime);
    ui->val_uploadUser->setText(fileInfo->user);
    ui->val_pv->setText(QString::number(fileInfo->pv));
}

filePropertyiInfoDialog::~filePropertyiInfoDialog()
{
    delete ui;
}
