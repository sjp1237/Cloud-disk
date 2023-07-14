/********************************************************************************
** Form generated from reading UI file 'titlewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEWIDGET_H
#define UI_TITLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_titleWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *set_but;
    QToolButton *hide_but;
    QToolButton *toolButton_3;

    void setupUi(QWidget *titleWidget)
    {
        if (titleWidget->objectName().isEmpty())
            titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        titleWidget->resize(550, 38);
        horizontalLayout = new QHBoxLayout(titleWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(titleWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(titleWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QString::fromUtf8("color:rgb(235, 7, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(170, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        set_but = new QToolButton(titleWidget);
        set_but->setObjectName(QString::fromUtf8("set_but"));
        set_but->setStyleSheet(QString::fromUtf8("border-image: url(:/res/login_setting.png);"));
        set_but->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(set_but);

        hide_but = new QToolButton(titleWidget);
        hide_but->setObjectName(QString::fromUtf8("hide_but"));
        hide_but->setStyleSheet(QString::fromUtf8("border-image: url(:/res/login_min.png);"));
        hide_but->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(hide_but);

        toolButton_3 = new QToolButton(titleWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/res/login_close.png);"));
        toolButton_3->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(toolButton_3);


        retranslateUi(titleWidget);

        QMetaObject::connectSlotsByName(titleWidget);
    } // setupUi

    void retranslateUi(QWidget *titleWidget)
    {
        titleWidget->setWindowTitle(QApplication::translate("titleWidget", "Form", nullptr));
        label_2->setText(QString());
        label->setText(QApplication::translate("titleWidget", "\345\234\250\347\272\277\347\275\221\347\233\230", nullptr));
        set_but->setText(QString());
        hide_but->setText(QString());
        toolButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class titleWidget: public Ui_titleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEWIDGET_H
