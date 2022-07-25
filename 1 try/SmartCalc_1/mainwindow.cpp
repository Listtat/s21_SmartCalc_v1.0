#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_window = new graphics();
    connect(graphics_window, &graphics::go_to_mainwindow, this, &MainWindow::show);

    credit_window = new credit();
    connect(credit_window, &credit::go_to_mainwindow, this, &MainWindow::show);

    deposit_window = new deposit();
    connect(deposit_window, &deposit::go_to_mainwindow, this, &MainWindow::show);

    // Кнопки
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_SIN, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_COS, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_TAN, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_ASIN, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_ACOS, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_ATAN, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_LOG, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_SQRT, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_MOD, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_LN, SIGNAL(clicked()), this, SLOT(press_button()));
    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(press_AC()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(press_equal()));
    connect(ui->pushButton_Graphics, SIGNAL(clicked()), this, SLOT(press_graphics()));
    connect(ui->pushButton_credit, SIGNAL(clicked()), this, SLOT(press_credit()));
    connect(ui->pushButton_deposit, SIGNAL(clicked()), this, SLOT(press_deposit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Обработка кнопок
void MainWindow::press_button()
{
    QPushButton *button = (QPushButton *) sender();

    if (ui->result_label->text().endsWith("0") && ui->result_label->text().size() == 1) {
        ui->result_label->setText(button->text());
    } else {
        if (ui->result_label->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result_label->setText(ui->result_label->text() + button->text());
        }
    }
}

// Обработка кнопки AC
void MainWindow::press_AC()
{
    ui->result_label->setText("");
    ui->value_of_x->setText("");
}

void MainWindow::press_equal()
{
    char* expression = new char(ui->result_label->text().length());
    QByteArray barr = ui->result_label->text().toLatin1();
    strlcpy(expression, barr, ui->result_label->text().length() + 1);

    char* value_of_x_str = new char(ui->value_of_x->text().length());
    QByteArray barr_of_x = ui->value_of_x->text().toLatin1();
    strlcpy(value_of_x_str, barr_of_x, ui->value_of_x->text().length() + 1);

    if ((ui->result_label->text().contains('x') && ui->value_of_x->text().length() != 0) || (!ui->result_label->text().contains('x') && ui->result_label->text().length() != 0)) {
        double result = 0.0;
        int error_code = calculator(expression, value_of_x_str, &result);

        if (error_code == 0) {
            QString valueAsString = QString::number(result, 'g', 15);
            ui->result_label->setText(valueAsString);
        } else if (error_code == 1) {
            QMessageBox::critical(this, "empty_expression", "Введите выражение");
        } else if (error_code == 2) {
            QMessageBox::critical(this, "inccorect", "Введено неккоректное выражение");
        } else if (error_code == 3) {
            QMessageBox::critical(this, "inccorect", "Выражение содержит более 255 символов");
        }
    } else {
        QMessageBox::critical(this, "without_x", "Введите значения для Х");
    }
    delete(expression);
    delete(value_of_x_str);
}

void MainWindow::on_result_label_returnPressed()
{
    press_equal();
}

void MainWindow::press_graphics()
{
    graphics_window->print_graph(ui->result_label->text());
    graphics_window->show();
    this->close();
}

void MainWindow::press_credit()
{
    credit_window->show();
    this->close();
}

void MainWindow::press_deposit()
{
    deposit_window->show();
    this->close();
}
