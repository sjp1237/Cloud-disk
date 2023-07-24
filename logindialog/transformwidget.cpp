#include "transformwidget.h"
#include "ui_transformwidget.h"
#include"uploadlayout.h"
#include"downloadlayout.h"
#include"logininfoinstance.h"


transformwidget::transformwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transformwidget)
{
    ui->setupUi(this);
//    m_vLayout-new QVBoxLayout;
//    m_vLayout->setParent(ui->tran_)
    uploadlayout* uploadLayout=uploadlayout::getInstant();
    uploadLayout->setParent(ui->scrollArea);

    downloadLayout* dlLyaout=downloadLayout::getInstant();
    dlLyaout->setParent(ui->scrollArea_2);

    connect(ui->tabWidget,&QTabWidget::currentChanged,this,[=](int index){
        if(index==2){
            //显示传输记录
            dispayDataRecord();
        }
    });
}



transformwidget::~transformwidget()
{
    delete ui;
}

void transformwidget::dispayDataRecord(QString path)
{
    //将传输记录显示到
    QString confFileName=QString("%1/%2.txt").arg(path).arg(logininfoinstance::getInstant()->user());
    QFile file(confFileName);
    if(!file.exists()){
        return;
    }

    if(file.open(QFile::ReadOnly))
    {
        QByteArray data=file.readAll();

        ui->tranLog_text->setText(QString::fromLocal8Bit(data));
        file.close();
    }

}


