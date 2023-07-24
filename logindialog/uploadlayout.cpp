#include "uploadlayout.h"



uploadlayout::uploadlayout()
{

}

uploadlayout* uploadlayout::instant=new uploadlayout;;

void uploadlayout::setParent(QWidget *parent)
{

    m_vLayout=new QVBoxLayout;
    m_vLayout->addStretch();//添加弹簧
    parent->setLayout(m_vLayout);
}
QVBoxLayout* uploadlayout::getVLayout()
{
    return m_vLayout;
}

uploadlayout *uploadlayout::getInstant()
{
    return instant;
}
