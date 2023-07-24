/********************************************************************************
** Form generated from reading UI file 'transformwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMWIDGET_H
#define UI_TRANSFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transformwidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *upload_list;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *download_list;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *tran_list;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *tranLog_text;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *clear_but;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *transformwidget)
    {
        if (transformwidget->objectName().isEmpty())
            transformwidget->setObjectName(QString::fromUtf8("transformwidget"));
        transformwidget->resize(678, 456);
        horizontalLayout = new QHBoxLayout(transformwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(transformwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        upload_list = new QWidget();
        upload_list->setObjectName(QString::fromUtf8("upload_list"));
        horizontalLayout_2 = new QHBoxLayout(upload_list);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scrollArea = new QScrollArea(upload_list);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 626, 382));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        tabWidget->addTab(upload_list, QString());
        download_list = new QWidget();
        download_list->setObjectName(QString::fromUtf8("download_list"));
        verticalLayout = new QVBoxLayout(download_list);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea_2 = new QScrollArea(download_list);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 626, 382));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);

        tabWidget->addTab(download_list, QString());
        tran_list = new QWidget();
        tran_list->setObjectName(QString::fromUtf8("tran_list"));
        verticalLayout_2 = new QVBoxLayout(tran_list);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea_3 = new QScrollArea(tran_list);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 626, 313));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tranLog_text = new QTextEdit(scrollAreaWidgetContents_3);
        tranLog_text->setObjectName(QString::fromUtf8("tranLog_text"));
        tranLog_text->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_3->addWidget(tranLog_text);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_2->addWidget(scrollArea_3);

        widget = new QWidget(tran_list);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(232, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        clear_but = new QToolButton(widget);
        clear_but->setObjectName(QString::fromUtf8("clear_but"));
        clear_but->setMinimumSize(QSize(100, 40));
        clear_but->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);\n"
"color: rgb(255, 36, 8);"));
        clear_but->setAutoRaise(true);

        horizontalLayout_3->addWidget(clear_but);

        horizontalSpacer_2 = new QSpacerItem(257, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget);

        tabWidget->addTab(tran_list, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(transformwidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(transformwidget);
    } // setupUi

    void retranslateUi(QWidget *transformwidget)
    {
        transformwidget->setWindowTitle(QApplication::translate("transformwidget", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(upload_list), QApplication::translate("transformwidget", "\344\270\212\344\274\240\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(download_list), QApplication::translate("transformwidget", "\344\270\213\350\275\275\345\210\227\350\241\250", nullptr));
        clear_but->setText(QApplication::translate("transformwidget", "\346\270\205\351\231\244\350\256\260\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tran_list), QApplication::translate("transformwidget", "\344\274\240\350\276\223\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transformwidget: public Ui_transformwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMWIDGET_H
