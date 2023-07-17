/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <buttongroup.h>
#include <myfile.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    myfile *myfile_page;
    QWidget *share_page;
    QWidget *load_page;
    QWidget *tran_page;
    QWidget *switch_page;
    QWidget *user_page;
    buttongroup *butgroup;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        myfile_page = new myfile();
        myfile_page->setObjectName(QString::fromUtf8("myfile_page"));
        stackedWidget->addWidget(myfile_page);
        share_page = new QWidget();
        share_page->setObjectName(QString::fromUtf8("share_page"));
        stackedWidget->addWidget(share_page);
        load_page = new QWidget();
        load_page->setObjectName(QString::fromUtf8("load_page"));
        stackedWidget->addWidget(load_page);
        tran_page = new QWidget();
        tran_page->setObjectName(QString::fromUtf8("tran_page"));
        stackedWidget->addWidget(tran_page);
        switch_page = new QWidget();
        switch_page->setObjectName(QString::fromUtf8("switch_page"));
        stackedWidget->addWidget(switch_page);
        user_page = new QWidget();
        user_page->setObjectName(QString::fromUtf8("user_page"));
        stackedWidget->addWidget(user_page);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        butgroup = new buttongroup(centralwidget);
        butgroup->setObjectName(QString::fromUtf8("butgroup"));

        gridLayout->addWidget(butgroup, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
