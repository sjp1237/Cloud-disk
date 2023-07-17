#ifndef MYMENU_H
#define MYMENU_H

#include <QObject>
#include<QMenu>
class MyMenu:public QMenu
{
public:
    MyMenu(QWidget* parent=nullptr);
};

#endif // MYMENU_H
