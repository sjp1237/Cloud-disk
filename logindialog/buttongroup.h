#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <QWidget>

namespace Ui {
class buttongroup;
}

class buttongroup : public QWidget
{
    Q_OBJECT

public:
    explicit buttongroup(QWidget *parent = nullptr);
    ~buttongroup();


    void setDefatleButton();

    void setUserName(QString name);

private slots:
    void on_toolButton_8_clicked();

    void on_myfile_btn_clicked();

    void on_share_btn_clicked();

    void on_load_btn_clicked();

    void on_tran_btn_clicked();

    void on_switch_btn_clicked();
    void on_hide_but1_clicked();

    void on_close_but_1_clicked();

    void on_user_btn_clicked();

signals:
    void myfilePage();
    void sharePage();
    void loadPage();
    void tranPage();
    void switchPage();
    void userPage();


    void hideWidget();

    void closeWidget();
private:
    Ui::buttongroup *ui;
};

#endif // BUTTONGROUP_H
