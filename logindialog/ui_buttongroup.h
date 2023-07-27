/********************************************************************************
** Form generated from reading UI file 'buttongroup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONGROUP_H
#define UI_BUTTONGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buttongroup
{
public:
    QHBoxLayout *horizontalLayout_2;
    QToolButton *user_btn;
    QToolButton *myfile_btn;
    QToolButton *share_btn;
    QToolButton *tran_btn;
    QToolButton *switch_btn;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *hide_but1;
    QToolButton *expend_but;
    QToolButton *close_but_1;
    QWidget *widget_2;

    void setupUi(QWidget *buttongroup)
    {
        if (buttongroup->objectName().isEmpty())
            buttongroup->setObjectName(QString::fromUtf8("buttongroup"));
        buttongroup->resize(793, 122);
        horizontalLayout_2 = new QHBoxLayout(buttongroup);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(11, 0, 0, -1);
        user_btn = new QToolButton(buttongroup);
        user_btn->setObjectName(QString::fromUtf8("user_btn"));
        user_btn->setEnabled(false);
        user_btn->setMinimumSize(QSize(70, 60));
        user_btn->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/title_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        user_btn->setIcon(icon);
        user_btn->setIconSize(QSize(50, 50));
        user_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        user_btn->setAutoRaise(true);

        horizontalLayout_2->addWidget(user_btn);

        myfile_btn = new QToolButton(buttongroup);
        myfile_btn->setObjectName(QString::fromUtf8("myfile_btn"));
        myfile_btn->setMinimumSize(QSize(70, 50));
        myfile_btn->setMaximumSize(QSize(70, 75));
        myfile_btn->setMouseTracking(false);
        myfile_btn->setTabletTracking(false);
        myfile_btn->setLayoutDirection(Qt::LeftToRight);
        myfile_btn->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/title_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        myfile_btn->setIcon(icon1);
        myfile_btn->setIconSize(QSize(50, 50));
        myfile_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        myfile_btn->setAutoRaise(true);

        horizontalLayout_2->addWidget(myfile_btn);

        share_btn = new QToolButton(buttongroup);
        share_btn->setObjectName(QString::fromUtf8("share_btn"));
        share_btn->setMinimumSize(QSize(70, 75));
        share_btn->setMaximumSize(QSize(70, 75));
        share_btn->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/title_share.png"), QSize(), QIcon::Normal, QIcon::Off);
        share_btn->setIcon(icon2);
        share_btn->setIconSize(QSize(50, 50));
        share_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        share_btn->setAutoRaise(true);

        horizontalLayout_2->addWidget(share_btn);

        tran_btn = new QToolButton(buttongroup);
        tran_btn->setObjectName(QString::fromUtf8("tran_btn"));
        tran_btn->setMinimumSize(QSize(70, 75));
        tran_btn->setMaximumSize(QSize(70, 75));
        tran_btn->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/title_data.png"), QSize(), QIcon::Normal, QIcon::Off);
        tran_btn->setIcon(icon3);
        tran_btn->setIconSize(QSize(50, 50));
        tran_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tran_btn->setAutoRaise(true);

        horizontalLayout_2->addWidget(tran_btn);

        switch_btn = new QToolButton(buttongroup);
        switch_btn->setObjectName(QString::fromUtf8("switch_btn"));
        switch_btn->setMinimumSize(QSize(70, 75));
        switch_btn->setMaximumSize(QSize(70, 75));
        switch_btn->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\273\221\344\275\223\";"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/title_change.png"), QSize(), QIcon::Normal, QIcon::Off);
        switch_btn->setIcon(icon4);
        switch_btn->setIconSize(QSize(50, 50));
        switch_btn->setPopupMode(QToolButton::DelayedPopup);
        switch_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        switch_btn->setAutoRaise(true);

        horizontalLayout_2->addWidget(switch_btn);

        horizontalSpacer = new QSpacerItem(232, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget = new QWidget(buttongroup);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hide_but1 = new QToolButton(widget);
        hide_but1->setObjectName(QString::fromUtf8("hide_but1"));
        hide_but1->setStyleSheet(QString::fromUtf8("border-image: url(:/res/title_min.png);"));

        horizontalLayout->addWidget(hide_but1);

        expend_but = new QToolButton(widget);
        expend_but->setObjectName(QString::fromUtf8("expend_but"));
        expend_but->setStyleSheet(QString::fromUtf8("border-image: url(:/res/title_max.png);"));

        horizontalLayout->addWidget(expend_but);

        close_but_1 = new QToolButton(widget);
        close_but_1->setObjectName(QString::fromUtf8("close_but_1"));
        close_but_1->setStyleSheet(QString::fromUtf8("border-image: url(:/res/title_close.png);"));

        horizontalLayout->addWidget(close_but_1);


        verticalLayout->addLayout(horizontalLayout);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(buttongroup);

        QMetaObject::connectSlotsByName(buttongroup);
    } // setupUi

    void retranslateUi(QWidget *buttongroup)
    {
        buttongroup->setWindowTitle(QApplication::translate("buttongroup", "Form", nullptr));
        user_btn->setText(QApplication::translate("buttongroup", "\346\270\270\345\256\242", nullptr));
        myfile_btn->setText(QApplication::translate("buttongroup", "\346\210\221\347\232\204\346\226\207\344\273\266", nullptr));
        share_btn->setText(QApplication::translate("buttongroup", "\345\205\261\344\272\253\345\210\227\350\241\250", nullptr));
        tran_btn->setText(QApplication::translate("buttongroup", "\344\274\240\350\276\223\345\210\227\350\241\250", nullptr));
        switch_btn->setText(QApplication::translate("buttongroup", "\345\210\207\346\215\242\347\224\250\346\210\267", nullptr));
        hide_but1->setText(QString());
        expend_but->setText(QString());
        close_but_1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class buttongroup: public Ui_buttongroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONGROUP_H
