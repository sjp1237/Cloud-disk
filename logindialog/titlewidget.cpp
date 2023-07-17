#include "titlewidget.h"
#include "ui_titlewidget.h"

titleWidget::titleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::titleWidget)
{

    ui->setupUi(this);
}

titleWidget::~titleWidget()
{
    delete ui;
}

void titleWidget::on_set_but_clicked()
{
    emit switchSettingPage();
}



void titleWidget::on_hide_but_clicked()
{
    emit hidePage();
}


void titleWidget::on_toolButton_3_clicked()
{
        emit closePage();
}
