#ifndef UPLOADLAYOUT_H
#define UPLOADLAYOUT_H
#include <QVBoxLayout>
#include<QWidget>
class uploadlayout
{
public:
    uploadlayout();

public:
    void setParent(QWidget* );
    QVBoxLayout* getVLayout();

    static uploadlayout* getInstant();
private:
    uploadlayout(uploadlayout*)=delete;
     uploadlayout(uploadlayout&)=delete;

     QVBoxLayout* m_vLayout;
     static uploadlayout* instant;
};

#endif // UPLOADLAYOUT_H
