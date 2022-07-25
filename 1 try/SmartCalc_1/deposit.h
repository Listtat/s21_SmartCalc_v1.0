#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>
#include <time.h>

extern "C" {
#include "../s21_smart_calc_1.0.h"
}

namespace Ui {
class deposit;
}

class deposit : public QWidget
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();

signals:
    void go_to_mainwindow();

private slots:
    void pushButton_back();
    void pushButton_result();

private:
    Ui::deposit *ui;
};

#endif // DEPOSIT_H
