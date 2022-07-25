#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QVector>

extern "C" {
#include "../s21_smart_calc_1.0.h"
}

namespace Ui {
class graphics;
}

class graphics : public QWidget
{
    Q_OBJECT

public:
    explicit graphics(QWidget *parent = nullptr);
    ~graphics();
    void print_graph(QString expression);
    QString expression_str;

signals:
    void go_to_mainwindow();

private slots:
    void pushButton_back();
    void push_draw();

private:
    Ui::graphics *ui;
};

#endif // GRAPHICS_H
