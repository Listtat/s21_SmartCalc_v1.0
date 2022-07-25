#include "s21_smart_calc_1.0.h"

double** s21_annuity(double loan_amount, int period, double rate) {
    double** result = malloc(period * sizeof(double*));
    for (int i = 0; i < period; i++) {
        result[i] = calloc(5, sizeof(double));
    }

    int tmp_period = period;
    double tmp_loan_amount = loan_amount;
    int i = 1;
    double rate_on_month = rate / 1200;
    double coef_annuity = (rate_on_month * pow(1 + rate_on_month, period)) /
            (pow(1 + rate_on_month, period) - 1);
    double monthly_payment = coef_annuity * loan_amount;
    monthly_payment = (round(monthly_payment * 100)) / 100;

    double percent_first_month = loan_amount * rate_on_month;
    percent_first_month = (ceil(percent_first_month * 100)) / 100;

    double repaid_amount = monthly_payment - percent_first_month;
    repaid_amount = (ceil(repaid_amount * 100)) / 100;

    tmp_loan_amount -= repaid_amount;
    tmp_period--;
    result[0][0] = i;
    result[0][1] = monthly_payment;
    result[0][2] = repaid_amount;
    result[0][3] = percent_first_month;
    result[0][4] = tmp_loan_amount;
    for (; tmp_period > 0; tmp_period--) {
        double percent_next_month = tmp_loan_amount * rate_on_month;
        percent_next_month = (round(percent_next_month * 100)) / 100;
        repaid_amount = monthly_payment - percent_next_month;
        tmp_loan_amount -= repaid_amount;
        if (tmp_loan_amount < 1e-2) {
            tmp_loan_amount = 0;
        }
        repaid_amount = monthly_payment - percent_next_month;
        tmp_loan_amount = (round(tmp_loan_amount * 100)) / 100;
        i++;
        result[i - 1][0] = i;
        result[i - 1][1] = monthly_payment;
        result[i - 1][2] = repaid_amount;
        result[i - 1][3] = percent_next_month;
        result[i - 1][4] = tmp_loan_amount;
    }
    return result;
}

double** s21_differentiated(double loan_amount, int period, double rate) {
    double** result = malloc(period * sizeof(double*));
    for (int i = 0; i < period; i++) {
        result[i] = calloc(100, sizeof(double));
    }
    double main_pay = loan_amount / period;
    main_pay = (round(main_pay * 100)) / 100;
    double tmp_loan_amount = loan_amount;

    for (int i = 0; i < period; i++) {
        double percent_sum = (loan_amount - main_pay * i) * rate / 100 / 12;
        double monthly_payment = main_pay + percent_sum;
        percent_sum = (round(percent_sum * 100)) / 100;
        monthly_payment = (round(monthly_payment * 100)) / 100;
        tmp_loan_amount -= main_pay;
        if (tmp_loan_amount < 1e-2) {
            tmp_loan_amount = 0;
        }
        tmp_loan_amount = (floor(tmp_loan_amount * 100)) / 100;
        result[i][0] = i + 1;
        result[i][1] = monthly_payment;
        result[i][2] = main_pay;
        result[i][3] = percent_sum;
        result[i][4] = tmp_loan_amount;
    }
    return result;
}
