/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <titlewidget.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_6;
    titleWidget *widget;
    QStackedWidget *stackedWidget;
    QWidget *login_page;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *tilet_label;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout;
    QLineEdit *password_edit;
    QLabel *password_label;
    QLabel *account_label;
    QLineEdit *account_edit;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *rember_checkBox;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *register_toolButton;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *login_toolButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *set_page;
    QGridLayout *gridLayout_5;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *ok_button;
    QWidget *widget_8;
    QGridLayout *gridLayout_4;
    QLineEdit *port_eidt;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *ip_edit;
    QSpacerItem *verticalSpacer_7;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *register_page;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QLineEdit *pasword_edit2;
    QLabel *label_7;
    QLineEdit *usr_edit;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *nickname_edit;
    QLineEdit *mailbox_edit;
    QLabel *label;
    QLineEdit *confirm_edit;
    QLineEdit *phone_edit;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(550, 500);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        verticalSpacer_6 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        widget = new titleWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(widget, 0, 0, 1, 3);

        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        login_page = new QWidget();
        login_page->setObjectName(QString::fromUtf8("login_page"));
        verticalLayout = new QVBoxLayout(login_page);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        tilet_label = new QLabel(login_page);
        tilet_label->setObjectName(QString::fromUtf8("tilet_label"));
        tilet_label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        tilet_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(tilet_label);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        password_edit = new QLineEdit(login_page);
        password_edit->setObjectName(QString::fromUtf8("password_edit"));
        password_edit->setMinimumSize(QSize(0, 30));
        password_edit->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(password_edit, 2, 1, 1, 1);

        password_label = new QLabel(login_page);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        gridLayout->addWidget(password_label, 2, 0, 1, 1);

        account_label = new QLabel(login_page);
        account_label->setObjectName(QString::fromUtf8("account_label"));

        gridLayout->addWidget(account_label, 0, 0, 1, 1);

        account_edit = new QLineEdit(login_page);
        account_edit->setObjectName(QString::fromUtf8("account_edit"));
        account_edit->setEnabled(true);
        account_edit->setMinimumSize(QSize(0, 30));
        account_edit->setMaximumSize(QSize(250, 500));

        gridLayout->addWidget(account_edit, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget_2 = new QWidget(login_page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rember_checkBox = new QCheckBox(widget_2);
        rember_checkBox->setObjectName(QString::fromUtf8("rember_checkBox"));

        horizontalLayout_2->addWidget(rember_checkBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        register_toolButton = new QToolButton(widget_2);
        register_toolButton->setObjectName(QString::fromUtf8("register_toolButton"));
        register_toolButton->setFocusPolicy(Qt::TabFocus);
        register_toolButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        register_toolButton->setAutoFillBackground(false);
        register_toolButton->setStyleSheet(QString::fromUtf8("font: 9pt \"\351\232\266\344\271\246\";\n"
"text-decoration: underline;\n"
"color: rgb(255, 103, 1);"));
        register_toolButton->setInputMethodHints(Qt::ImhNone);
        register_toolButton->setPopupMode(QToolButton::DelayedPopup);
        register_toolButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(register_toolButton);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(login_page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        login_toolButton = new QToolButton(widget_3);
        login_toolButton->setObjectName(QString::fromUtf8("login_toolButton"));
        login_toolButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login_toolButton->sizePolicy().hasHeightForWidth());
        login_toolButton->setSizePolicy(sizePolicy);
        login_toolButton->setMinimumSize(QSize(120, 50));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        login_toolButton->setFont(font);
        login_toolButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/balckButton.png);"));
        login_toolButton->setIconSize(QSize(24, 20));
        login_toolButton->setAutoExclusive(false);
        login_toolButton->setAutoRepeatDelay(200);
        login_toolButton->setAutoRepeatInterval(100);
        login_toolButton->setAutoRaise(false);

        horizontalLayout_3->addWidget(login_toolButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget->addWidget(login_page);
        set_page = new QWidget();
        set_page->setObjectName(QString::fromUtf8("set_page"));
        gridLayout_5 = new QGridLayout(set_page);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget_9 = new QWidget(set_page);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_12 = new QLabel(widget_9);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_12);


        gridLayout_5->addWidget(widget_9, 1, 0, 1, 1);

        widget_10 = new QWidget(set_page);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_6 = new QHBoxLayout(widget_10);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ok_button = new QToolButton(widget_10);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setMinimumSize(QSize(120, 50));
        ok_button->setStyleSheet(QString::fromUtf8("border-image: url(:/res/balckButton.png);"));

        horizontalLayout_6->addWidget(ok_button);


        gridLayout_5->addWidget(widget_10, 4, 0, 1, 1);

        widget_8 = new QWidget(set_page);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        gridLayout_4 = new QGridLayout(widget_8);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        port_eidt = new QLineEdit(widget_8);
        port_eidt->setObjectName(QString::fromUtf8("port_eidt"));

        gridLayout_4->addWidget(port_eidt, 1, 1, 1, 1);

        label_10 = new QLabel(widget_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(widget_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        ip_edit = new QLineEdit(widget_8);
        ip_edit->setObjectName(QString::fromUtf8("ip_edit"));

        gridLayout_4->addWidget(ip_edit, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_8, 2, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_7, 0, 0, 1, 1);

        widget_11 = new QWidget(set_page);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_8 = new QHBoxLayout(widget_11);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        toolButton = new QToolButton(widget_11);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("color:rgb(255, 103, 1);\n"
"text-decoration: underline;\n"
"font: 9pt \"Agency FB\";\n"
"font: 9pt \"\351\273\221\344\275\223\";"));
        toolButton->setAutoRaise(true);

        horizontalLayout_8->addWidget(toolButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        gridLayout_5->addWidget(widget_11, 3, 0, 1, 1);

        stackedWidget->addWidget(set_page);
        register_page = new QWidget();
        register_page->setObjectName(QString::fromUtf8("register_page"));
        verticalLayout_2 = new QVBoxLayout(register_page);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        widget_5 = new QWidget(register_page);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);


        verticalLayout_2->addWidget(widget_5);

        widget_4 = new QWidget(register_page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pasword_edit2 = new QLineEdit(widget_4);
        pasword_edit2->setObjectName(QString::fromUtf8("pasword_edit2"));

        gridLayout_3->addWidget(pasword_edit2, 2, 1, 1, 1);

        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 4, 0, 1, 1);

        usr_edit = new QLineEdit(widget_4);
        usr_edit->setObjectName(QString::fromUtf8("usr_edit"));

        gridLayout_3->addWidget(usr_edit, 0, 1, 1, 1);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        label_8 = new QLabel(widget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 5, 0, 1, 1);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 3, 0, 1, 1);

        nickname_edit = new QLineEdit(widget_4);
        nickname_edit->setObjectName(QString::fromUtf8("nickname_edit"));

        gridLayout_3->addWidget(nickname_edit, 1, 1, 1, 1);

        mailbox_edit = new QLineEdit(widget_4);
        mailbox_edit->setObjectName(QString::fromUtf8("mailbox_edit"));

        gridLayout_3->addWidget(mailbox_edit, 5, 1, 1, 1);

        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        confirm_edit = new QLineEdit(widget_4);
        confirm_edit->setObjectName(QString::fromUtf8("confirm_edit"));

        gridLayout_3->addWidget(confirm_edit, 3, 1, 1, 1);

        phone_edit = new QLineEdit(widget_4);
        phone_edit->setObjectName(QString::fromUtf8("phone_edit"));

        gridLayout_3->addWidget(phone_edit, 4, 1, 1, 1);


        verticalLayout_2->addWidget(widget_4);

        widget_6 = new QWidget(register_page);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolButton_4 = new QToolButton(widget_6);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\256\213\344\275\223\";\n"
"text-decoration: underline;\n"
"color:rgb(255, 103, 1)"));
        toolButton_4->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_6);

        widget_7 = new QWidget(register_page);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        toolButton_3 = new QToolButton(widget_7);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(120, 50));
        toolButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/res/balckButton.png);"));

        horizontalLayout_5->addWidget(toolButton_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_2->addWidget(widget_7);

        stackedWidget->addWidget(register_page);

        gridLayout_2->addWidget(stackedWidget, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 2, 1, 1);


        retranslateUi(Dialog);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        tilet_label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        password_label->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        account_label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        rember_checkBox->setText(QApplication::translate("Dialog", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        register_toolButton->setText(QApplication::translate("Dialog", "\346\262\241\346\234\211\350\264\246\345\217\267,\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        login_toolButton->setText(QApplication::translate("Dialog", "\347\231\273\345\275\225", nullptr));
        label_12->setText(QApplication::translate("Dialog", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        ok_button->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        label_10->setText(QApplication::translate("Dialog", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        label_11->setText(QApplication::translate("Dialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        toolButton->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        label_9->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label_7->setText(QApplication::translate("Dialog", "\346\211\213\346\234\272", nullptr));
        label_5->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201", nullptr));
        label_8->setText(QApplication::translate("Dialog", "\351\202\256\347\256\261", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\346\230\265\347\247\260", nullptr));
        label_6->setText(QApplication::translate("Dialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        toolButton_4->setText(QApplication::translate("Dialog", "\345\267\262\346\234\211\350\264\246\345\217\267\357\274\214\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        toolButton_3->setText(QApplication::translate("Dialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
