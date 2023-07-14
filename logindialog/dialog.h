#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"common.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_register_toolButton_clicked();

    void on_toolButton_4_clicked();

    void switchSettingPage();
    void hidePage();

    void closePage();
    void on_toolButton_clicked();

    void on_login_toolButton_clicked();

    void on_toolButton_3_clicked();

private:
    Ui::Dialog *ui;
    Common* m_common;
    void paintEvent(QPaintEvent*);
};

#endif // DIALOG_H
