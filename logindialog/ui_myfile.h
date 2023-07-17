/********************************************************************************
** Form generated from reading UI file 'myfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFILE_H
#define UI_MYFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myfile
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *myfile)
    {
        if (myfile->objectName().isEmpty())
            myfile->setObjectName(QString::fromUtf8("myfile"));
        myfile->resize(700, 478);
        horizontalLayout = new QHBoxLayout(myfile);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget = new QListWidget(myfile);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);


        retranslateUi(myfile);

        QMetaObject::connectSlotsByName(myfile);
    } // setupUi

    void retranslateUi(QWidget *myfile)
    {
        myfile->setWindowTitle(QApplication::translate("myfile", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myfile: public Ui_myfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFILE_H
