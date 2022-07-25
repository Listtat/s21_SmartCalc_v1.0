/********************************************************************************
** Form generated from reading UI file 'credit_result.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_RESULT_H
#define UI_CREDIT_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_credit_result
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_overpay;
    QLabel *label_full_pay;

    void setupUi(QWidget *credit_result)
    {
        if (credit_result->objectName().isEmpty())
            credit_result->setObjectName(QString::fromUtf8("credit_result"));
        credit_result->resize(850, 827);
        tableWidget = new QTableWidget(credit_result);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 850, 725));
        QFont font;
        font.setPointSize(13);
        tableWidget->setFont(font);
        label = new QLabel(credit_result);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 740, 191, 41));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        label_2 = new QLabel(credit_result);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 740, 251, 41));
        label_2->setFont(font1);
        label_overpay = new QLabel(credit_result);
        label_overpay->setObjectName(QString::fromUtf8("label_overpay"));
        label_overpay->setGeometry(QRect(570, 740, 171, 41));
        label_overpay->setFont(font1);
        label_full_pay = new QLabel(credit_result);
        label_full_pay->setObjectName(QString::fromUtf8("label_full_pay"));
        label_full_pay->setGeometry(QRect(220, 740, 171, 41));
        label_full_pay->setFont(font1);

        retranslateUi(credit_result);

        QMetaObject::connectSlotsByName(credit_result);
    } // setupUi

    void retranslateUi(QWidget *credit_result)
    {
        credit_result->setWindowTitle(QCoreApplication::translate("credit_result", "Form", nullptr));
        label->setText(QCoreApplication::translate("credit_result", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260, \321\200\321\203\320\261.:", nullptr));
        label_2->setText(QCoreApplication::translate("credit_result", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203, \321\200\321\203\320\261.:", nullptr));
        label_overpay->setText(QCoreApplication::translate("credit_result", "111", nullptr));
        label_full_pay->setText(QCoreApplication::translate("credit_result", "132", nullptr));
    } // retranslateUi

};

namespace Ui {
    class credit_result: public Ui_credit_result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_RESULT_H
