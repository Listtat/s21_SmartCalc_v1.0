#include "deposit.h"
#include "ui_deposit.h"

deposit::deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deposit)
{
    ui->setupUi(this);

    connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(pushButton_back()));
    connect(ui->pushButton_result, SIGNAL(clicked()), this, SLOT(pushButton_result()));
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setMinimumDate(QDate::currentDate());
    ui->dateEdit->setMaximumDate(QDate::currentDate().addDays(1000000));
}

deposit::~deposit()
{
    delete ui;
}

void deposit::pushButton_back()
{
    this->close();
    emit go_to_mainwindow();
}

void deposit::pushButton_result()
{
    QDate old_date;
    QDate new_date;
//    double loan_amount = ui->main_sum->text().toDouble();
//    double rate = ui->rate->text().toDouble();
    int period = 0;
    int old_day = 0;
    int old_month = 0;
    int old_year = 0;
    int new_month = 0;
    int new_year = 0;
    old_day = ui->dateEdit->date().day();
    old_month = ui->dateEdit->date().month();
    old_year = ui->dateEdit->date().year();
    old_date.setDate(old_year, old_month, old_day);

    if (ui->comboBox_period->currentIndex() == 0) {
        period = ui->lineEdit_period->text().toInt();
    } else if (ui->comboBox_period->currentIndex() == 1) {
        int read_month = ui->lineEdit_period->text().toInt();
        new_month = old_month + read_month;
        new_year = old_year;
        if (new_month > 12) {
            new_year = old_year + new_month / 12;
            new_month = new_month % 13;
        }
        new_date.setDate(new_year, new_month, old_day);
        period = old_date.daysTo(new_date);
    } else if (ui->comboBox_period->currentIndex() == 2) {
        new_year = old_year + ui->lineEdit_period->text().toInt();
        new_month = old_month;
        new_date.setDate(new_year, new_month, old_day);
        period = old_date.daysTo(new_date);
    }
}
