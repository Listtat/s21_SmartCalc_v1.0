#ifndef SRC_S21_SMART_CALC_1_0_H_
#define SRC_S21_SMART_CALC_1_0_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

enum enum_type {
    open_bracket = 0,
    close_bracket = 1,
    x = 2,
    number = 3,
    add = 4,
    sub = 5,
    multiply = 6,
    divide = 7,
    e_exp = 8,
    e_mod = 9,
    e_sin = 10,
    e_cos = 11,
    e_tan = 12,
    e_asin = 13,
    e_acos = 14,
    e_atan = 15,
    e_sqrt = 16,
    e_ln = 17,
    e_log = 18
};

enum operand_type {
    NUMBER = 0,
    POINT = 1,
    X = 2
};

struct list {
    double value;
    enum enum_type type;
    int priority;
    struct list* next;
};

int calculator(char* expression, char* value_of_x_str, double *result);
int s21_check_expression(char *expression, double value_of_x, struct list** head);
void s21_delete_space(char* expression);
int s21_check_operand(char ch, int* i, char* mas_for_number, char* expression, struct list **head);
int s21_check_mas_for_number(char ch, char* mas_for_number);
int s21_check_penultimate_char(char *mas_for_number);
int s21_is_digit(char ch);
int s21_check_func(char ch, int* i, struct list** head, char* expression);
int s21_check_operation(char ch, int* i, struct list **head, char* expression);
int s21_check_parenthesis(char ch, struct list **head, int* count_parenthesis);
struct list* s21_create_node(double value, enum enum_type type, int priority);
void s21_add_to_list(struct list **head, double value, enum enum_type type, int priority);
int s21_check_type_of_last_node(struct list** head);
int s21_check_possible_add_operand(char* mas_for_number, struct list** head,
        double value, int type, int priority);
int s21_check_possible_add_operation(struct list** head, int type, int priority, char ch);


void s21_create_reverse_notation_list(struct list* head, struct list** reverse_notation);
void s21_push(struct list** stack, double value, int type, int priority);
void s21_remove_first_node(struct list** head);

int s21_calculate(struct list* head, double *result);
void s21_calculating_an_action(struct list* tmp, struct list* buf, int count_shifts, int shift_left);

// credit_calc
double** s21_annuity(double loan_amount, int period, double rate);
double** s21_differentiated(double loan_amount, int period, double rate);

#endif //  SRC_S21_SMART_CALC_1_0_H_
