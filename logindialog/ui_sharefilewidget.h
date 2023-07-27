/********************************************************************************
** Form generated from reading UI file 'sharefilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAREFILEWIDGET_H
#define UI_SHAREFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShareFileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *ShareFileWidget)
    {
        if (ShareFileWidget->objectName().isEmpty())
            ShareFileWidget->setObjectName(QString::fromUtf8("ShareFileWidget"));
        ShareFileWidget->resize(700, 478);
        verticalLayout = new QVBoxLayout(ShareFileWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ShareFileWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(ShareFileWidget);

        QMetaObject::connectSlotsByName(ShareFileWidget);
    } // setupUi

    void retranslateUi(QWidget *ShareFileWidget)
    {
        ShareFileWidget->setWindowTitle(QApplication::translate("ShareFileWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShareFileWidget: public Ui_ShareFileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAREFILEWIDGET_H
