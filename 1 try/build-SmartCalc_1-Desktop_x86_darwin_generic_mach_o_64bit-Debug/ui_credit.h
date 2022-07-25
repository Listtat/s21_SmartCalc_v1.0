/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_credit
{
public:
    QPushButton *pushButton_back;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *main_sum;
    QLabel *label_3;
    QLineEdit *rate;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_period;
    QPushButton *pushButton_result;
    QLabel *label_6;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_diff;
    QRadioButton *radioButton_annuity;

    void setupUi(QWidget *credit)
    {
        if (credit->objectName().isEmpty())
            credit->setObjectName(QString::fromUtf8("credit"));
        credit->resize(650, 353);
        pushButton_back = new QPushButton(credit);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(10, 10, 100, 32));
        label = new QLabel(credit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 211, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(credit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 160, 211, 41));
        label_2->setFont(font);
        main_sum = new QLineEdit(credit);
        main_sum->setObjectName(QString::fromUtf8("main_sum"));
        main_sum->setGeometry(QRect(10, 100, 211, 41));
        main_sum->setFont(font);
        label_3 = new QLabel(credit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 100, 41, 41));
        label_3->setFont(font);
        rate = new QLineEdit(credit);
        rate->setObjectName(QString::fromUtf8("rate"));
        rate->setGeometry(QRect(10, 210, 211, 41));
        rate->setFont(font);
        label_4 = new QLabel(credit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 210, 41, 41));
        label_4->setFont(font);
        label_5 = new QLabel(credit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 50, 51, 41));
        label_5->setFont(font);
        lineEdit_period = new QLineEdit(credit);
        lineEdit_period->setObjectName(QString::fromUtf8("lineEdit_period"));
        lineEdit_period->setGeometry(QRect(300, 100, 211, 41));
        lineEdit_period->setFont(font);
        pushButton_result = new QPushButton(credit);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setGeometry(QRect(150, 270, 291, 61));
        pushButton_result->setFont(font);
        label_6 = new QLabel(credit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(310, 160, 51, 41));
        label_6->setFont(font);
        comboBox = new QComboBox(credit);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(510, 90, 131, 61));
        comboBox->setFont(font);
        layoutWidget = new QWidget(credit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(350, 200, 231, 55));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_diff = new QRadioButton(layoutWidget);
        radioButton_diff->setObjectName(QString::fromUtf8("radioButton_diff"));
        radioButton_diff->setFont(font);

        verticalLayout->addWidget(radioButton_diff);

        radioButton_annuity = new QRadioButton(layoutWidget);
        radioButton_annuity->setObjectName(QString::fromUtf8("radioButton_annuity"));
        radioButton_annuity->setFont(font);

        verticalLayout->addWidget(radioButton_annuity);


        retranslateUi(credit);

        QMetaObject::connectSlotsByName(credit);
    } // setupUi

    void retranslateUi(QWidget *credit)
    {
        credit->setWindowTitle(QCoreApplication::translate("credit", "Form", nullptr));
        pushButton_back->setText(QCoreApplication::translate("credit", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("credit", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("credit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("credit", "\321\200\321\203\320\261.", nullptr));
        label_4->setText(QCoreApplication::translate("credit", "%", nullptr));
        label_5->setText(QCoreApplication::translate("credit", "\320\241\321\200\320\276\320\272:", nullptr));
        pushButton_result->setText(QCoreApplication::translate("credit", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("credit", "\320\242\320\270\320\277:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("credit", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("credit", "\320\233\320\265\321\202", nullptr));

        radioButton_diff->setText(QCoreApplication::translate("credit", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        radioButton_annuity->setText(QCoreApplication::translate("credit", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class credit: public Ui_credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
