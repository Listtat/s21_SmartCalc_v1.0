#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "graphics.h"
#include "credit.h"
#include "deposit.h"

extern "C" {
#include "../s21_smart_calc_1.0.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void press_button();
    void press_AC();
    void press_equal();
    void on_result_label_returnPressed();
    void press_graphics();
    void press_credit();
    void press_deposit();

private:
    Ui::MainWindow *ui;
    graphics *graphics_window;
    credit *credit_window;
    deposit *deposit_window;
};

#endif // MAINWINDOW_H
