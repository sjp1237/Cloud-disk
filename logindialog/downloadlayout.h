#ifndef DOWNLOADLAYOUT_H
#define DOWNLOADLAYOUT_H
#include <QVBoxLayout>
#include<QWidget>
class downloadLayout
{
public:
    downloadLayout();

public:
    void setParent(QWidget* );
    QVBoxLayout* getVLayout();

    static downloadLayout* getInstant();
private:
    downloadLayout(downloadLayout*)=delete;
     downloadLayout(downloadLayout&)=delete;

     QVBoxLayout* m_vLayout;
     static downloadLayout* instant;
};

#endif // DOWNLOADLAYOUT_H




