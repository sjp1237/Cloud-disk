#ifndef FILEDATAPROGRESS_H
#define FILEDATAPROGRESS_H

#include <QWidget>
#include<QString>
namespace Ui {
class filedataProgress;
}

class filedataProgress : public QWidget
{
    Q_OBJECT

public:
    explicit filedataProgress(QWidget *parent = nullptr);
    ~filedataProgress();

    void setName(QString name);
    void setValue(int value,int maxValue);
private:
    Ui::filedataProgress *ui;
};

#endif // FILEDATAPROGRESS_H
