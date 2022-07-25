#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QIntValidator>
#include "credit_result.h"

extern "C" {
#include "../s21_smart_calc_1.0.h"
}

namespace Ui {
class credit;
}

class credit : public QWidget
{
    Q_OBJECT

public:
    explicit credit(QWidget *parent = nullptr);
    ~credit();

signals:
    void go_to_mainwindow();

private slots:
    void pushButton_back();
    void pushButton_result();

private:
    Ui::credit *ui;
    credit_result *credit_result_window;
    QDoubleValidator validator;
    QIntValidator int_validator;
};

#endif // CREDIT_H
