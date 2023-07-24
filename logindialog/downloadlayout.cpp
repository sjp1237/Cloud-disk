#include "downloadlayout.h"

downloadLayout::downloadLayout()
{

}




downloadLayout* downloadLayout::instant=new downloadLayout;;

void downloadLayout::setParent(QWidget *parent)
{

    m_vLayout=new QVBoxLayout;
    m_vLayout->addStretch();//添加弹簧.使进度条放在最上面
    parent->setLayout(m_vLayout);
}
QVBoxLayout* downloadLayout::getVLayout()
{
    return m_vLayout;
}

downloadLayout *downloadLayout::getInstant()
{
    return instant;
}
