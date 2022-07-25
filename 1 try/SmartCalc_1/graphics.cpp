#include "graphics.h"
#include "ui_graphics.h"

graphics::graphics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphics)
{
    ui->setupUi(this);
    connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(pushButton_back()));
    connect(ui->draw, SIGNAL(clicked()), this, SLOT(push_draw()));  // new
}

graphics::~graphics()
{
    delete ui;
}

void graphics::pushButton_back()
{
    this->close();
    emit go_to_mainwindow();
}

void graphics::push_draw()
{
    expression_str = ui->result_label->text();
    print_graph(expression_str);
}

void graphics::print_graph(QString expression)
{
    ui->result_label->setText(expression);
    expression_str = expression;
    ui->widget->clearGraphs();

    char* str = new char(expression.length());
    QByteArray barr = expression.toLatin1();
    strlcpy(str, barr, expression.length() + 1);

    double x_begin = ui->min_x->text().toDouble();
    double x_end = ui->max_x->text().toDouble();
    double y_begin = ui->min_y->text().toDouble();
    double y_end = ui->max_y->text().toDouble();
    double h = 0.01;
    double X;
//    int N = (x_begin - x_end) / h + 2;
    QVector<double> x,y;

    ui->widget->xAxis->setRange(x_begin, x_end);
    ui->widget->yAxis->setRange(y_begin, y_end);

    int error_code = 0;

    if (x_begin > -1000000 && x_end < 1000000 && y_begin > -1000000 && y_end < 1000000) {
        for (X = x_begin; X < x_end && error_code == 0; X += h) {
            char str_of_x[256] = "";
            memset(str_of_x, '\0', 256);
            sprintf(str_of_x, "%lf", X);
            x.push_back(X);
            double res = 0.0;
            error_code = calculator(str, str_of_x, &res);
            y.push_back(res);
        }
        if (error_code == 1) {
            QMessageBox::critical(this, "empty_expression", "Введите выражение");
        } else if (error_code == 2) {
            QMessageBox::critical(this, "inccorect", "Введено неккоректное выражение");
        } else if (error_code == 3) {
            QMessageBox::critical(this, "inccorect", "Выражение содержит более 255 символов");
        } else {
            ui->widget->addGraph();
            ui->widget->graph(0)->addData(x,y);
            ui->widget->replot();

            x.clear();
            y.clear();
        }
    } else {
        QMessageBox::critical(this, "inccorect", "Введите корректные значения для X и Y");
    }
}
