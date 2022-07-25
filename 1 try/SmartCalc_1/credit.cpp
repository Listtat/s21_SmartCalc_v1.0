#include "credit.h"
#include "ui_credit.h"

credit::credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::credit)
{
    ui->setupUi(this);

    connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(pushButton_back()));
    connect(ui->pushButton_result, SIGNAL(clicked()), this, SLOT(pushButton_result()));


    QLocale locale(QLocale::English);
    validator.setLocale(locale);
    validator.setNotation(QDoubleValidator::StandardNotation);
    ui->main_sum->setValidator(&validator);
    ui->lineEdit_period->setValidator(&int_validator);
    ui->rate->setValidator(&validator);
}

credit::~credit()
{
    delete ui;
}

void credit::pushButton_back()
{
    this->close();
    emit go_to_mainwindow();
}

void credit::pushButton_result()
{
    credit_result_window = new credit_result();
    double loan_amount = ui->main_sum->text().toDouble();
    double rate = ui->rate->text().toDouble();
    int period;
    if (!ui->main_sum->text().contains(',') && !ui->rate->text().contains(',')) {
        if (ui->comboBox->currentIndex() == 0) {
            period = ui->lineEdit_period->text().toInt();
        } else {
            period = 12 * ui->lineEdit_period->text().toInt();
        }

        if (ui->main_sum->text().length() != 0 && ui->rate->text().length() != 0 && ui->lineEdit_period->text().length() != 0) {
            double** result_table = NULL;

            if (ui->radioButton_annuity->isChecked()) {
                result_table = s21_annuity(loan_amount, period, rate);
                credit_result_window->show();
            } else if (ui->radioButton_diff->isChecked()) {
                result_table = s21_differentiated(loan_amount, period, rate);
                credit_result_window->show();
            } else {
                QMessageBox::information(this, "Выбор", "Выберите тип кредита");
            }

            credit_result_window->fill_table(result_table, period);
        } else {
            QMessageBox::information(this, "empty_expression", "Введите данные");
        }
    } else {
        QMessageBox::information(this, "Наличие запятой", "Введите данные через точку");
    }
}
