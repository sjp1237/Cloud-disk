#include "dialog.h"
#include <QApplication>
#include"common.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    QString s=Common::getInstant()->getConfValue("login","user");
    qDebug()<<s;
    return a.exec();
}
