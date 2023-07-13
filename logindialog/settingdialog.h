#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QWidget>

namespace Ui {
class settingdialog;
}

class settingdialog : public QWidget
{
    Q_OBJECT

public:
    explicit settingdialog(QWidget *parent = nullptr);
    ~settingdialog();

private:
    Ui::settingdialog *ui;
};

#endif // SETTINGDIALOG_H
