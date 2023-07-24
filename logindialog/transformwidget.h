#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>
#include"uploadlayout.h"
#include"common.h"
namespace Ui {
class transformwidget;
}

class transformwidget : public QWidget
{
    Q_OBJECT

public:
    explicit transformwidget(QWidget *parent = nullptr);
    ~transformwidget();
   QVBoxLayout* getVLayout();
private:
    Ui::transformwidget *ui;
    QVBoxLayout* m_vLayout;
    uploadlayout* m_uploadLayout;

    void dispayDataRecord(QString path=RECORD_DIR);
};

#endif // TRANSFORMWIDGET_H
