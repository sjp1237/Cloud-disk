/********************************************************************************
** Form generated from reading UI file 'filepropertyiinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPROPERTYIINFODIALOG_H
#define UI_FILEPROPERTYIINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filePropertyiInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_fileName;
    QLabel *val_fileName;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_uploadUser;
    QLabel *val_uploadUser;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_uploadTime;
    QLabel *val_uploadTime;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_fileSize;
    QLabel *val_fileSize;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_shareStatus;
    QLabel *val_shareStatus;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_download;
    QLabel *val_download;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_pv;
    QLabel *val_pv;

    void setupUi(QDialog *filePropertyiInfoDialog)
    {
        if (filePropertyiInfoDialog->objectName().isEmpty())
            filePropertyiInfoDialog->setObjectName(QString::fromUtf8("filePropertyiInfoDialog"));
        filePropertyiInfoDialog->resize(417, 433);
        verticalLayout = new QVBoxLayout(filePropertyiInfoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(filePropertyiInfoDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbl_fileName = new QLabel(widget);
        lbl_fileName->setObjectName(QString::fromUtf8("lbl_fileName"));

        horizontalLayout->addWidget(lbl_fileName);

        val_fileName = new QLabel(widget);
        val_fileName->setObjectName(QString::fromUtf8("val_fileName"));

        horizontalLayout->addWidget(val_fileName);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(filePropertyiInfoDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbl_uploadUser = new QLabel(widget_2);
        lbl_uploadUser->setObjectName(QString::fromUtf8("lbl_uploadUser"));

        horizontalLayout_2->addWidget(lbl_uploadUser);

        val_uploadUser = new QLabel(widget_2);
        val_uploadUser->setObjectName(QString::fromUtf8("val_uploadUser"));

        horizontalLayout_2->addWidget(val_uploadUser);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(filePropertyiInfoDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lbl_uploadTime = new QLabel(widget_3);
        lbl_uploadTime->setObjectName(QString::fromUtf8("lbl_uploadTime"));

        horizontalLayout_3->addWidget(lbl_uploadTime);

        val_uploadTime = new QLabel(widget_3);
        val_uploadTime->setObjectName(QString::fromUtf8("val_uploadTime"));

        horizontalLayout_3->addWidget(val_uploadTime);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(filePropertyiInfoDialog);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbl_fileSize = new QLabel(widget_4);
        lbl_fileSize->setObjectName(QString::fromUtf8("lbl_fileSize"));

        horizontalLayout_4->addWidget(lbl_fileSize);

        val_fileSize = new QLabel(widget_4);
        val_fileSize->setObjectName(QString::fromUtf8("val_fileSize"));

        horizontalLayout_4->addWidget(val_fileSize);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(filePropertyiInfoDialog);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lbl_shareStatus = new QLabel(widget_5);
        lbl_shareStatus->setObjectName(QString::fromUtf8("lbl_shareStatus"));

        horizontalLayout_5->addWidget(lbl_shareStatus);

        val_shareStatus = new QLabel(widget_5);
        val_shareStatus->setObjectName(QString::fromUtf8("val_shareStatus"));

        horizontalLayout_5->addWidget(val_shareStatus);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(filePropertyiInfoDialog);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lbl_download = new QLabel(widget_6);
        lbl_download->setObjectName(QString::fromUtf8("lbl_download"));

        horizontalLayout_6->addWidget(lbl_download);

        val_download = new QLabel(widget_6);
        val_download->setObjectName(QString::fromUtf8("val_download"));

        horizontalLayout_6->addWidget(val_download);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(filePropertyiInfoDialog);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lbl_pv = new QLabel(widget_7);
        lbl_pv->setObjectName(QString::fromUtf8("lbl_pv"));

        horizontalLayout_7->addWidget(lbl_pv);

        val_pv = new QLabel(widget_7);
        val_pv->setObjectName(QString::fromUtf8("val_pv"));

        horizontalLayout_7->addWidget(val_pv);


        verticalLayout->addWidget(widget_7);


        retranslateUi(filePropertyiInfoDialog);

        QMetaObject::connectSlotsByName(filePropertyiInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *filePropertyiInfoDialog)
    {
        filePropertyiInfoDialog->setWindowTitle(QApplication::translate("filePropertyiInfoDialog", "Dialog", nullptr));
        lbl_fileName->setText(QApplication::translate("filePropertyiInfoDialog", "\346\226\207\344\273\266\345\220\215\347\247\260\357\274\232", nullptr));
        val_fileName->setText(QApplication::translate("filePropertyiInfoDialog", "\346\226\207\344\273\2662", nullptr));
        lbl_uploadUser->setText(QApplication::translate("filePropertyiInfoDialog", "\344\270\212\344\274\240\350\200\205\357\274\232", nullptr));
        val_uploadUser->setText(QApplication::translate("filePropertyiInfoDialog", "sjp", nullptr));
        lbl_uploadTime->setText(QApplication::translate("filePropertyiInfoDialog", "\344\270\212\344\274\240\346\227\266\351\227\264\357\274\232", nullptr));
        val_uploadTime->setText(QApplication::translate("filePropertyiInfoDialog", "\346\227\266\351\227\264", nullptr));
        lbl_fileSize->setText(QApplication::translate("filePropertyiInfoDialog", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", nullptr));
        val_fileSize->setText(QApplication::translate("filePropertyiInfoDialog", "1024kb", nullptr));
        lbl_shareStatus->setText(QApplication::translate("filePropertyiInfoDialog", "\345\210\206\344\272\253\347\212\266\346\200\201\357\274\232", nullptr));
        val_shareStatus->setText(QApplication::translate("filePropertyiInfoDialog", "\345\267\262\347\273\217\345\210\206\344\272\253", nullptr));
        lbl_download->setText(QApplication::translate("filePropertyiInfoDialog", "\344\270\213\350\275\275\345\234\260\345\235\200\357\274\232", nullptr));
        val_download->setText(QApplication::translate("filePropertyiInfoDialog", "\346\265\213\350\257\225", nullptr));
        lbl_pv->setText(QApplication::translate("filePropertyiInfoDialog", "\344\270\213\350\275\275\351\207\217\357\274\232", nullptr));
        val_pv->setText(QApplication::translate("filePropertyiInfoDialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filePropertyiInfoDialog: public Ui_filePropertyiInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPROPERTYIINFODIALOG_H
