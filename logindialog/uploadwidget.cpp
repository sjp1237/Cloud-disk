#include "uploadwidget.h"
#include "ui_uploadwidget.h"

upLoadWidget::upLoadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::upLoadWidget)
{
    ui->setupUi(this);
}

upLoadWidget::~upLoadWidget()
{
    delete ui;
}
