#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

namespace Ui {
class titleWidget;
}

class titleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit titleWidget(QWidget *parent = nullptr);
    ~titleWidget();

signals:
    void switchSettingPage();
    void hidePage();
    void closePage();
private slots:
    void on_set_but_clicked();

    void on_hide_but_clicked();

    void on_toolButton_3_clicked();

private:
    Ui::titleWidget *ui;
};

#endif // TITLEWIDGET_H
