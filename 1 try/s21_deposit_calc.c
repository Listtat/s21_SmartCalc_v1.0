#include "s21_smart_calc_1.0.h"

int main() {
    double loan_amount = 100000;
    int period = 10;
    double year_rate = 5;
    double day_rate = year_rate / 36500;
    day_rate = (round(day_rate * 1000000)) / 1000000;
    int flag = 1;
    s21_deposit(loan_amount, period, day_rate, flag);
}

void s21_deposit(double loan_amount, int period, double rate, int cap, int period_pay, int* date) {
//    int* leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//    int* simple_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (cap == 0) {
        if (period_pay == 0) {
            for (int i = 0; i < period; i++) {
                double accrued_interest = rate * loan_amount;
                printf("%lf\n", accrued_interest);
            }
        } else if (period_pay == 1) {
            int period_week = period / 7;
            int remnant = period % 7;
            for (int i = 0; i < period_week; i++) {
                for (int j = 0; j < 7; j++) {
                    double accrued_interest = rate * loan_amount;
                }
            }
            for (int i = 0; i < remnant; i++) {
                double accrued_interest = rate * loan_amount;
            }
        }
    } else {
        double sum = 0.0;
        for (int i = 0; i < period; i++) {
            double accrued_interest = rate * loan_amount;
            accrued_interest = accrued_interest * 1000;
            if (fmod(accrued_interest, 10) < 6) {
                accrued_interest = floor(accrued_interest / 10) / 100;
            } else {
                accrued_interest = round(accrued_interest / 10) / 100;
            }
            printf("%lf\n", accrued_interest);
            loan_amount += accrued_interest;
            sum += accrued_interest;
        }
        printf("%lf\n", sum);
    }
}

double** s21_deposit_without_cap_day(double loan_amount, int period, double rate,
                                     int cap, int period_pay, int* date) {
    int simple_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int* use_year = simple_year;
    double** result = malloc(period * sizeof(double*));
    for (int i = 0; i < period; i++) {
        result[i] = calloc(7, sizeof(double));
    }

    if (s21_check_leap_year(date[2])) {
        simple_year[1] = 29;
    }
    use_year[date[1]] = date[0];

    for (int i = 0; i < period; i++) {
        result[i][0] = date[0];
        result[i][1] = date[1];
        result[i][2] = date[2];
        double accrued_interest = rate * loan_amount;
        result[i][3] = accrued_interest;
        printf("%lf\n", accrued_interest);
    }
}

int s21_check_leap_year(int year) {
    int flag = 0;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                flag = 1;
            }
        }
    }
    return flag;
}
