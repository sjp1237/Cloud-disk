/********************************************************************************
** Form generated from reading UI file 'uploadwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADWIDGET_H
#define UI_UPLOADWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_upLoadWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *uploadListWidget;

    void setupUi(QWidget *upLoadWidget)
    {
        if (upLoadWidget->objectName().isEmpty())
            upLoadWidget->setObjectName(QString::fromUtf8("upLoadWidget"));
        upLoadWidget->resize(700, 478);
        verticalLayout = new QVBoxLayout(upLoadWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        uploadListWidget = new QListWidget(upLoadWidget);
        uploadListWidget->setObjectName(QString::fromUtf8("uploadListWidget"));

        verticalLayout->addWidget(uploadListWidget);


        retranslateUi(upLoadWidget);

        QMetaObject::connectSlotsByName(upLoadWidget);
    } // setupUi

    void retranslateUi(QWidget *upLoadWidget)
    {
        upLoadWidget->setWindowTitle(QApplication::translate("upLoadWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class upLoadWidget: public Ui_upLoadWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADWIDGET_H
