/********************************************************************************
** Form generated from reading UI file 'graphics.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICS_H
#define UI_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graphics
{
public:
    QPushButton *pushButton_back;
    QCustomPlot *widget;
    QLabel *label;
    QLineEdit *min_x;
    QLabel *label_2;
    QLineEdit *max_x;
    QPushButton *draw;
    QLabel *label_3;
    QLineEdit *min_y;
    QLineEdit *max_y;
    QLabel *label_4;
    QLineEdit *result_label;

    void setupUi(QWidget *graphics)
    {
        if (graphics->objectName().isEmpty())
            graphics->setObjectName(QString::fromUtf8("graphics"));
        graphics->resize(711, 722);
        pushButton_back = new QPushButton(graphics);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(600, 630, 100, 32));
        widget = new QCustomPlot(graphics);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 109, 681, 511));
        label = new QLabel(graphics);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 630, 61, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        min_x = new QLineEdit(graphics);
        min_x->setObjectName(QString::fromUtf8("min_x"));
        min_x->setGeometry(QRect(70, 630, 81, 31));
        min_x->setFont(font);
        min_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(graphics);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 630, 61, 31));
        label_2->setFont(font);
        max_x = new QLineEdit(graphics);
        max_x->setObjectName(QString::fromUtf8("max_x"));
        max_x->setGeometry(QRect(230, 630, 81, 31));
        max_x->setFont(font);
        max_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        draw = new QPushButton(graphics);
        draw->setObjectName(QString::fromUtf8("draw"));
        draw->setGeometry(QRect(490, 630, 100, 32));
        label_3 = new QLabel(graphics);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 680, 61, 31));
        label_3->setFont(font);
        min_y = new QLineEdit(graphics);
        min_y->setObjectName(QString::fromUtf8("min_y"));
        min_y->setGeometry(QRect(70, 680, 81, 31));
        min_y->setFont(font);
        min_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        max_y = new QLineEdit(graphics);
        max_y->setObjectName(QString::fromUtf8("max_y"));
        max_y->setGeometry(QRect(230, 680, 81, 31));
        max_y->setFont(font);
        max_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(graphics);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 680, 61, 31));
        label_4->setFont(font);
        result_label = new QLineEdit(graphics);
        result_label->setObjectName(QString::fromUtf8("result_label"));
        result_label->setGeometry(QRect(10, 10, 691, 81));
        result_label->setFont(font);

        retranslateUi(graphics);

        QMetaObject::connectSlotsByName(graphics);
    } // setupUi

    void retranslateUi(QWidget *graphics)
    {
        graphics->setWindowTitle(QCoreApplication::translate("graphics", "Form", nullptr));
        pushButton_back->setText(QCoreApplication::translate("graphics", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("graphics", "MIN X:", nullptr));
        min_x->setText(QCoreApplication::translate("graphics", "-10", nullptr));
        label_2->setText(QCoreApplication::translate("graphics", "MAX X:", nullptr));
        max_x->setText(QCoreApplication::translate("graphics", "10", nullptr));
        draw->setText(QCoreApplication::translate("graphics", "draw graph", nullptr));
        label_3->setText(QCoreApplication::translate("graphics", "MIN Y:", nullptr));
        min_y->setText(QCoreApplication::translate("graphics", "-10", nullptr));
        max_y->setText(QCoreApplication::translate("graphics", "10", nullptr));
        label_4->setText(QCoreApplication::translate("graphics", "MAX Y:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphics: public Ui_graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICS_H
