/********************************************************************************
** Form generated from reading UI file 'filedataprogress.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEDATAPROGRESS_H
#define UI_FILEDATAPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filedataProgress
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *filedataProgress)
    {
        if (filedataProgress->objectName().isEmpty())
            filedataProgress->setObjectName(QString::fromUtf8("filedataProgress"));
        filedataProgress->resize(650, 50);
        horizontalLayout = new QHBoxLayout(filedataProgress);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(filedataProgress);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        progressBar = new QProgressBar(filedataProgress);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        retranslateUi(filedataProgress);

        QMetaObject::connectSlotsByName(filedataProgress);
    } // setupUi

    void retranslateUi(QWidget *filedataProgress)
    {
        filedataProgress->setWindowTitle(QApplication::translate("filedataProgress", "Form", nullptr));
        label->setText(QApplication::translate("filedataProgress", "\346\226\207\344\273\266\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filedataProgress: public Ui_filedataProgress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEDATAPROGRESS_H
