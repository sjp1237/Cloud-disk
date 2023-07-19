#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"common.h"
#include"mainwindow.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT




public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


    void readConf();
    void saveLoginInfoData(QString username, QString token, QString ip, QString port);


    void showMainWindow(QString account);//显示云盘主界面
private slots:
    void on_register_toolButton_clicked();

    void on_toolButton_4_clicked();

    void switchSettingPage();
    void hidePage();

    void closePage();
    void on_toolButton_clicked();

    void on_login_toolButton_clicked();

//    void on_toolButton_3_clicked();

    void on_ok_button_clicked();

    void on_reg_but_clicked();

private:
    Ui::Dialog *ui;
    Common* m_common;
    QNetworkAccessManager* manger;

    MainWindow* mainwindow;
    void paintEvent(QPaintEvent*);
};

#endif // DIALOG_H
