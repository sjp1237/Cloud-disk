#include "filedataprogress.h"
#include "ui_filedataprogress.h"

filedataProgress::filedataProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filedataProgress)
{
    ui->setupUi(this);
}

filedataProgress::~filedataProgress()
{
    delete ui;
}




void filedataProgress::setName(QString name)
{
    ui->label->setText(name);
}
void filedataProgress::setValue(int value,int maxValue)
{
    ui->progressBar->setValue(value*100/maxValue);
}
