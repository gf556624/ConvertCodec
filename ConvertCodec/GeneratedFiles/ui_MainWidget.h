/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditDir;
    QPushButton *btnSelect;
    QPushButton *btnConvert;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbtnUtf8;
    QRadioButton *rbtnGBK;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;

    void setupUi(QWidget *MainWidgetClass)
    {
        if (MainWidgetClass->objectName().isEmpty())
            MainWidgetClass->setObjectName(QStringLiteral("MainWidgetClass"));
        MainWidgetClass->resize(600, 386);
        verticalLayout = new QVBoxLayout(MainWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditDir = new QLineEdit(MainWidgetClass);
        lineEditDir->setObjectName(QStringLiteral("lineEditDir"));

        horizontalLayout->addWidget(lineEditDir);

        btnSelect = new QPushButton(MainWidgetClass);
        btnSelect->setObjectName(QStringLiteral("btnSelect"));

        horizontalLayout->addWidget(btnSelect);

        btnConvert = new QPushButton(MainWidgetClass);
        btnConvert->setObjectName(QStringLiteral("btnConvert"));

        horizontalLayout->addWidget(btnConvert);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        rbtnUtf8 = new QRadioButton(MainWidgetClass);
        rbtnUtf8->setObjectName(QStringLiteral("rbtnUtf8"));
        rbtnUtf8->setChecked(true);

        horizontalLayout_2->addWidget(rbtnUtf8);

        rbtnGBK = new QRadioButton(MainWidgetClass);
        rbtnGBK->setObjectName(QStringLiteral("rbtnGBK"));

        horizontalLayout_2->addWidget(rbtnGBK);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(MainWidgetClass);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(MainWidgetClass);

        QMetaObject::connectSlotsByName(MainWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MainWidgetClass)
    {
        MainWidgetClass->setWindowTitle(QApplication::translate("MainWidgetClass", "MainWidget", nullptr));
        btnSelect->setText(QApplication::translate("MainWidgetClass", "\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271", nullptr));
        btnConvert->setText(QApplication::translate("MainWidgetClass", "\350\275\254\346\215\242", nullptr));
        rbtnUtf8->setText(QApplication::translate("MainWidgetClass", "\350\275\254\346\215\242\344\270\272UTF-8", nullptr));
        rbtnGBK->setText(QApplication::translate("MainWidgetClass", "\350\275\254\346\215\242\344\270\272GBK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidgetClass: public Ui_MainWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
