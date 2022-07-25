#include "credit_result.h"
#include "ui_credit_result.h"

credit_result::credit_result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::credit_result)
{
    ui->setupUi(this);

    this->createUI(QStringList() << ("№ Месяца")
                                 << ("Сумма платежа, руб.")
                                 << ("Платеж по основному долгу, руб.")
                                 << ("Платеж по процентам, руб.")
                                 << ("Остаток долга, руб."));
    ui->tableWidget->setStyleSheet( "QTableView { gridline-color: green; }" );


}

credit_result::~credit_result()
{
    delete ui;
}

void credit_result::createUI(const QStringList &headers)
{
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setShowGrid(true);

    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

void credit_result::fill_table(double** result, int period)
{
    double full_pay = 0.0;
    double overpay = 0.0;
    for (int i = 0; i < period; i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(result[i][0], 'g', 15)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(result[i][1], 'g', 15)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(result[i][2], 'g', 15)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(result[i][3], 'g', 15)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(result[i][4], 'g', 15)));
        full_pay += result[i][1];
        ui->label_full_pay->setText(QString::number(full_pay, 'g', 15));
        overpay += result[i][3];
        ui->label_overpay->setText(QString::number(overpay, 'g', 15));
    }
    ui->tableWidget->resizeColumnsToContents();

    for (int i = 0; i < period; i++) {
        free(result[i]);
    }
    free(result);
    result = NULL;
}
