/********************************************************************************
** Form generated from reading UI file 'deposit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_H
#define UI_DEPOSIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deposit
{
public:
    QPushButton *pushButton_back;
    QLabel *label;
    QLineEdit *main_sum;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_period;
    QComboBox *comboBox_period;
    QLabel *label_4;
    QLineEdit *rate;
    QLabel *label_5;
    QLabel *label_6;
    QDateEdit *dateEdit;
    QPushButton *pushButton_result;
    QLabel *label_7;
    QComboBox *comboBox_period_pay;
    QCheckBox *checkBox_capit;

    void setupUi(QWidget *deposit)
    {
        if (deposit->objectName().isEmpty())
            deposit->setObjectName(QString::fromUtf8("deposit"));
        deposit->resize(851, 739);
        pushButton_back = new QPushButton(deposit);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(10, 10, 100, 32));
        label = new QLabel(deposit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 141, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        main_sum = new QLineEdit(deposit);
        main_sum->setObjectName(QString::fromUtf8("main_sum"));
        main_sum->setGeometry(QRect(10, 90, 161, 41));
        main_sum->setFont(font);
        label_3 = new QLabel(deposit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 90, 41, 41));
        label_3->setFont(font);
        label_2 = new QLabel(deposit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 150, 171, 41));
        label_2->setFont(font);
        lineEdit_period = new QLineEdit(deposit);
        lineEdit_period->setObjectName(QString::fromUtf8("lineEdit_period"));
        lineEdit_period->setGeometry(QRect(10, 190, 81, 41));
        lineEdit_period->setFont(font);
        comboBox_period = new QComboBox(deposit);
        comboBox_period->addItem(QString());
        comboBox_period->addItem(QString());
        comboBox_period->addItem(QString());
        comboBox_period->setObjectName(QString::fromUtf8("comboBox_period"));
        comboBox_period->setGeometry(QRect(90, 190, 131, 41));
        comboBox_period->setFont(font);
        label_4 = new QLabel(deposit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 50, 181, 41));
        label_4->setFont(font);
        rate = new QLineEdit(deposit);
        rate->setObjectName(QString::fromUtf8("rate"));
        rate->setGeometry(QRect(230, 90, 171, 41));
        rate->setFont(font);
        label_5 = new QLabel(deposit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(410, 90, 41, 41));
        label_5->setFont(font);
        label_6 = new QLabel(deposit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 150, 171, 41));
        label_6->setFont(font);
        dateEdit = new QDateEdit(deposit);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(230, 190, 131, 41));
        dateEdit->setFont(font);
        pushButton_result = new QPushButton(deposit);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setGeometry(QRect(250, 610, 291, 61));
        pushButton_result->setFont(font);
        label_7 = new QLabel(deposit);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 250, 221, 41));
        label_7->setFont(font);
        comboBox_period_pay = new QComboBox(deposit);
        comboBox_period_pay->addItem(QString());
        comboBox_period_pay->addItem(QString());
        comboBox_period_pay->addItem(QString());
        comboBox_period_pay->addItem(QString());
        comboBox_period_pay->addItem(QString());
        comboBox_period_pay->addItem(QString());
        comboBox_period_pay->addItem(QString());
        comboBox_period_pay->setObjectName(QString::fromUtf8("comboBox_period_pay"));
        comboBox_period_pay->setGeometry(QRect(10, 290, 201, 41));
        comboBox_period_pay->setFont(font);
        checkBox_capit = new QCheckBox(deposit);
        checkBox_capit->setObjectName(QString::fromUtf8("checkBox_capit"));
        checkBox_capit->setGeometry(QRect(10, 330, 261, 31));
        checkBox_capit->setFont(font);

        retranslateUi(deposit);

        QMetaObject::connectSlotsByName(deposit);
    } // setupUi

    void retranslateUi(QWidget *deposit)
    {
        deposit->setWindowTitle(QCoreApplication::translate("deposit", "Form", nullptr));
        pushButton_back->setText(QCoreApplication::translate("deposit", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("deposit", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("deposit", "\321\200\321\203\320\261.", nullptr));
        label_2->setText(QCoreApplication::translate("deposit", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217:", nullptr));
        comboBox_period->setItemText(0, QCoreApplication::translate("deposit", "\320\224\320\275\320\265\320\271", nullptr));
        comboBox_period->setItemText(1, QCoreApplication::translate("deposit", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        comboBox_period->setItemText(2, QCoreApplication::translate("deposit", "\320\233\320\265\321\202", nullptr));

        label_4->setText(QCoreApplication::translate("deposit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        label_5->setText(QCoreApplication::translate("deposit", "%", nullptr));
        label_6->setText(QCoreApplication::translate("deposit", "\320\235\320\260\321\207\320\260\320\273\320\276 \321\201\321\200\320\276\320\272\320\260:", nullptr));
        pushButton_result->setText(QCoreApplication::translate("deposit", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("deposit", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202:", nullptr));
        comboBox_period_pay->setItemText(0, QCoreApplication::translate("deposit", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        comboBox_period_pay->setItemText(1, QCoreApplication::translate("deposit", "\320\232\320\260\320\266\320\264\321\203\321\216 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        comboBox_period_pay->setItemText(2, QCoreApplication::translate("deposit", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        comboBox_period_pay->setItemText(3, QCoreApplication::translate("deposit", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        comboBox_period_pay->setItemText(4, QCoreApplication::translate("deposit", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        comboBox_period_pay->setItemText(5, QCoreApplication::translate("deposit", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));
        comboBox_period_pay->setItemText(6, QCoreApplication::translate("deposit", "\320\222 \320\272\320\276\320\275\321\206\320\265 \321\201\321\200\320\276\320\272\320\260", nullptr));

        checkBox_capit->setText(QCoreApplication::translate("deposit", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deposit: public Ui_deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_H
