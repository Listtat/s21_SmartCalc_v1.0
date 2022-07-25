#include "s21_smart_calc_1.0.h"

int calculator(char* expression, char* value_of_x_str, double *result) {
    int error_code = 0;
    if (strlen(expression) < 256) {
        double value_of_x;
        if (strlen(value_of_x_str)) {
            value_of_x = atof(value_of_x_str);
        }
        struct list *head = NULL;
        struct list *reverse_notation = NULL;

        if (strlen(expression) > 0) {
            if (!(error_code = s21_check_expression(expression, value_of_x, &head))) {
                s21_create_reverse_notation_list(head, &reverse_notation);
                s21_calculate(reverse_notation, result);
            } else {
                error_code = 2;
            }
        } else {
            error_code = 1;
        }
    } else {
        error_code = 3;
    }
    return error_code;
}

/**
 * Проверка выражения на корректность и создание односвязного списка из лексем
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_check_expression(char *expression, double value_of_x, struct list** head) {
    int error_code = 0;
    char mas_for_number[256] = "";
    memset(mas_for_number, '\0', 256);
    int count_parenthesis = 0;

    s21_delete_space(expression);

    for (int i = 0; !error_code; i++) {
        if (expression[i] == '\0' && !strlen(mas_for_number)) {
            break;
        }
        if (!s21_check_operand(expression[i], &i, mas_for_number, expression, head)) {
            continue;
        } else if (strlen(mas_for_number)) {
            if (!s21_is_digit(mas_for_number[strlen(mas_for_number) - 1])) {
                double value = atof(mas_for_number);
                error_code = s21_check_possible_add_operand(mas_for_number, head, value, number, 0);
                i--;
            } else if (mas_for_number[0] == 'x') {
                error_code = s21_check_possible_add_operand(mas_for_number, head, value_of_x, x, 0);
                i--;
            }
        } else if (!s21_check_operation(expression[i], &i, head, expression)) {
            continue;
        } else if (!s21_check_parenthesis(expression[i], head, &count_parenthesis)) {
            continue;
        } else {
            error_code = 1;
        }
    }
    int check = s21_check_type_of_last_node(head);
    if (count_parenthesis) {
        error_code = 1;
    } else if (check != close_bracket && check != x && check != number) {
        error_code = 1;
    }
    return error_code;
}

/**
 * Удаление пробелов
 * @param expression
 */
void s21_delete_space(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ') {
            int j = i;
            for (; expression[j] == ' '; j++) {}
            if (expression[j] != '\0') {
                expression[i] = expression[j];
                expression[j] = ' ';
            } else {
                memset((expression + i), '\0', strlen((expression + i)));
                break;
            }
        }
    }
}

/**
 * Проверка операнда на корректность
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_check_operand(char ch, int* i, char* mas_for_number, char* expression, struct list **head) {
    int error_code = 0;
    size_t length_mas = strlen(mas_for_number);

    if (!s21_is_digit(ch) || ch == '.' || ch == 'x') {
        error_code = s21_check_mas_for_number(ch, mas_for_number);
    } else if (!length_mas && (ch == 'a' || ch == 'c' || ch == 'l' || ch == 's' || ch == 't')) {
        error_code = s21_check_func(ch, i, head, expression);
    } else {
        error_code = 1;
    }
    return error_code;
}

/**
 * Проверка возможности добавления считанного числа или Х в массив и добавление соответственно
 * @return SUCCESS - 0
 * @return FAIL - 1
 */
int s21_check_mas_for_number(char ch, char* mas_for_number) {
    int error_code = 0;
    int penultimate_char = 0;
    size_t length_mas = strlen(mas_for_number);

    if (length_mas) {
        penultimate_char = s21_check_penultimate_char(mas_for_number);
    }

    if (length_mas && penultimate_char == X) {
        error_code = 1;
    } else if (ch == '.' && (!length_mas || penultimate_char == POINT)) {
        error_code = 1;
    } else if (ch == 'x' && length_mas && (penultimate_char == POINT || penultimate_char == NUMBER)) {
        error_code = 1;
    } else {
        mas_for_number[length_mas] = ch;
    }
    return error_code;
}

/**
 * Проверка предпоследнего символа массива с числами
 * @return 0 - NUMBER
 * @return 1 - POINT
 * @return 2 - X
 */
int s21_check_penultimate_char(char *mas_for_number) {
    int error_code = NUMBER;

    if (!s21_is_digit(mas_for_number[strlen(mas_for_number) - 1])) {
        error_code = NUMBER;
    } else if (mas_for_number[strlen(mas_for_number) - 1] == '.') {
        error_code = POINT;
    } else if (mas_for_number[strlen(mas_for_number) - 1] == 'x') {
        error_code = X;
    }
    return error_code;
}

/**
 * Проверка является символ цифрой
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_is_digit(char ch) {
    int error_code = 0;

    if (ch < 48 || ch > 57) {
        error_code = 1;
    }
    return error_code;
}

/**
 * Проверка, поступила ли на вход функция
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_check_func(char ch, int* i, struct list** head, char* expression) {
    int error_code = 0;
    char mas_for_number[256] = "";

    if (ch == 'a') {
        if (strncmp((expression + *i), "acos", 4) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_acos, 5);
            *i += 3;
        } else if (strncmp((expression + *i), "asin", 4) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_asin, 5);
            *i += 3;
        } else if (strncmp(expression + *i, "atan", 4) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_atan, 5);
            *i += 3;
        } else {
            error_code = 1;
        }
    } else if (ch == 'c') {
        if (strncmp((expression + *i), "cos", 3) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_cos, 4);
            *i += 2;
        } else {
            error_code = 1;
        }
    } else if (ch == 'l') {
        if (strncmp((expression + *i), "ln", 2) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_ln, 4);
            *i += 1;
        } else if (strncmp((expression + *i), "log", 3) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_log, 4);
            *i += 2;
        } else {
            error_code = 1;
        }
    } else if (ch == 's') {
        if (strncmp((expression + *i), "sin", 3) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_sin, 4);
            *i += 2;
        } else if (strncmp((expression + *i), "sqrt", 4) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_sqrt, 4);
            *i += 3;
        } else {
            error_code = 1;
        }
    } else if (ch == 't') {
        if (strncmp((expression + *i), "tan", 3) == 0) {
            error_code = s21_check_possible_add_operand(mas_for_number, head, 0, e_tan, 4);
            *i += 2;
        } else {
            error_code = 1;
        }
    } else {
        error_code = 1;
    }
    return error_code;
}

/**
 * Проверка, поступил ли на вход символ операции
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_check_operation(char ch, int* i, struct list **head, char* expression) {
    int error_code = 0;

    if (ch == '+') {
        error_code = s21_check_possible_add_operation(head, add, 1, ch);
    } else if (ch == '-') {
        error_code = s21_check_possible_add_operation(head, sub, 1, ch);
    } else if (ch == '*') {
        error_code = s21_check_possible_add_operation(head, multiply, 2, ch);
    } else if (ch == '/') {
        error_code = s21_check_possible_add_operation(head, divide, 2, ch);
    } else if (ch == '^') {
        error_code = s21_check_possible_add_operation(head, e_exp, 3, ch);
    } else if (ch == 'm') {
        if (strncmp((expression + *i), "mod", 3) == 0) {
            error_code = s21_check_possible_add_operation(head, e_mod, 2, ch);
            *i += 2;
        } else {
            error_code = 1;
        }
    } else {
        error_code = 1;
    }
    return error_code;
}

/**
 * Проверка, поступил ли на вход символ скобки
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_check_parenthesis(char ch, struct list **head, int* count_parenthesis) {
    int error_code = 0;

    if (ch == '(') {
        int type = s21_check_type_of_last_node(head);
        if (type < 1 || type > 3) {
            s21_add_to_list(head, 0, 0, -1);
            *count_parenthesis += 1;
        } else {
            error_code = 1;
        }
    } else if (ch == ')') {
        if (count_parenthesis) {
            int type = s21_check_type_of_last_node(head);
            if (type == 1 || type == 2 || type == 3) {
                s21_add_to_list(head, 0, 1, -1);
                *count_parenthesis -= 1;
            } else {
                error_code = 1;
            }
        } else {
            error_code = 1;
        }
    } else {
        error_code = 1;
    }
    return error_code;
}


/**
 * Создание нового элемента списка
 * @return node
 */
struct list* s21_create_node(double value, enum enum_type type, int priority) {
    struct list *node = malloc(sizeof(struct list));

    if (node != NULL) {
        node->value = value;
        node->type = type;
        node->priority = priority;
        node->next = NULL;
    } else {
        exit(1);
    }

    return node;
}

/**
 * Добавление нового элемента в конец списка
 */
void s21_add_to_list(struct list **head, double value, enum enum_type type, int priority) {
    struct list* node = s21_create_node(value, type, priority);

    if (*head == NULL) {
        *head = node;
    } else {
        struct list *tmp = *head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    node = NULL;
}

/**
 * Проверка типа последнего элемента односвязного списка
 * @return тип элемента
 */
int s21_check_type_of_last_node(struct list** head) {
    int type = 0;

    if (*head == NULL) {
        type = -1;
    } else {
        struct list *tmp = *head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        type = tmp->type;
    }
    return type;
}

/**
 * Проверка на корректность добавления операнда
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_check_possible_add_operand(char* mas_for_number, struct list** head,
        double value, int type, int priority) {
    int error_code = 0;

    int type_last_node = s21_check_type_of_last_node(head);
    if (type_last_node != 1 && type_last_node != 2 && type_last_node != 3) {
        s21_add_to_list(head, value, type, priority);
        memset(mas_for_number, '\0', 256);
    } else {
        error_code = 1;
    }
    return error_code;
}

/**
 * Проверка на корректность добавления знака операции
 * @return 0 - SUCCESS
 * @return 1 - FAIL
 */
int s21_check_possible_add_operation(struct list** head, int type, int priority, char ch) {
    int error_code = 0;

    int type_last_node = s21_check_type_of_last_node(head);
    if (type_last_node >= 1 && type_last_node <= 3) {
        s21_add_to_list(head, 0, type, priority);
    } else if ((type_last_node == -1 || type_last_node == 0) && (ch == '+' || ch == '-')) {
        if (ch == '+') {
            s21_add_to_list(head, 0, number, 0);
            s21_add_to_list(head, 0, add, 1);
        } else {
            s21_add_to_list(head, 0, number, 0);
            s21_add_to_list(head, 0, sub, 1);
        }
    } else {
        error_code = 1;
    }
    return error_code;
}

/**
 * Создание односвязного списка в виде обратной польской нотации
 */
void s21_create_reverse_notation_list(struct list* head, struct list** reverse_notation) {
    struct list* stack = NULL;
    struct list* help_head = head;

    while (1) {
        if (help_head->type == open_bracket) {
            s21_push(&stack, 0, open_bracket, -1);
        } else if (help_head->type == close_bracket) {
            while (stack->type != open_bracket) {
                s21_add_to_list(reverse_notation, stack->value, stack->type, stack->priority);
                s21_remove_first_node(&stack);
            }
            s21_remove_first_node(&stack);
        } else if (help_head->type == x || help_head->type == number) {
            s21_add_to_list(reverse_notation, help_head->value, help_head->type, help_head->priority);
        } else if (help_head->type > 3) {
            int priority = 0;
            if (stack != NULL) {
                priority = stack->priority;
            }
            if (help_head->priority > priority) {
                s21_push(&stack, help_head->value, help_head->type, help_head->priority);
            } else {
                while (stack != NULL && help_head->priority <= stack->priority) {
                    s21_add_to_list(reverse_notation, stack->value, stack->type, stack->priority);
                    s21_remove_first_node(&stack);
                }
                s21_push(&stack, help_head->value, help_head->type, help_head->priority);
            }
        }
        if (help_head->next != NULL) {
            help_head = help_head->next;
        } else {
            break;
        }
    }
    while (stack != NULL) {
        s21_add_to_list(reverse_notation, stack->value, stack->type, stack->priority);
        s21_remove_first_node(&stack);
    }
}

/**
 * Добавление элемента в начало списка
 */
void s21_push(struct list** stack, double value, int type, int priority) {
    struct list *new_node = s21_create_node(value, type, priority);

    if (*stack == NULL) {
        *stack = new_node;
    } else {
        new_node->next = *stack;
        *stack = new_node;
    }
    new_node = NULL;
}

/**
 * Удаление первого элемента односвязного списка
 */
void s21_remove_first_node(struct list** head) {
    if (*head != NULL) {
        struct list* tmp = *head;
        *head = tmp->next;
        free(tmp);
    }
}

int s21_calculate(struct list* head, double *result) {
    int error_code = 0;
    while (1) {
        if (head->next == NULL) {
            *result = head->value;
            free(head);
            head = NULL;
            break;
        }
        int count_shifts = 0;
        struct list *tmp = head;
        struct list *buf = head;
        while (tmp->type == x || tmp->type == number) {
            tmp = tmp->next;
            count_shifts++;
        }
        if (tmp->type > 3 && tmp->type < 10) {
            s21_calculating_an_action(tmp, buf, count_shifts, 2);
        } else if (tmp->type >= 10) {
            s21_calculating_an_action(tmp, buf, count_shifts, 1);
        } else {
            error_code = 1;
        }
    }
    return error_code;
}

void s21_calculating_an_action(struct list* tmp, struct list* buf, int count_shifts, int shift_left) {
    int index = count_shifts - shift_left;
    for (int i = index; i > 0; i--) {
        buf = buf->next;
    }
    struct list *buf2 = buf;
    double value = buf->value;
    buf = buf->next;
    if (tmp->type == add) {
        buf2->value = value + buf->value;
    } else if (tmp->type == sub) {
        buf2->value = value - buf->value;
    } else if (tmp->type == multiply) {
        buf2->value = value * buf->value;
    } else if (tmp->type == divide) {
        buf2->value = value / buf->value;
    } else if (tmp->type == e_exp) {
        buf2->value = pow(value, buf->value);
    } else if (tmp->type == e_mod) {
        buf2->value = fmod(value, buf->value);
    } else if (tmp->type == e_sin) {
        buf2->value = sin(value);
    } else if (tmp->type == e_cos) {
        buf2->value = cos(value);
    } else if (tmp->type == e_tan) {
        buf2->value = tan(value);
    } else if (tmp->type == e_asin) {
        buf2->value = asin(value);
    } else if (tmp->type == e_acos) {
        buf2->value = acos(value);
    } else if (tmp->type == e_atan) {
        buf2->value = atan(value);
    } else if (tmp->type == e_sqrt) {
        buf2->value = sqrt(value);
    } else if (tmp->type == e_ln) {
        buf2->value = log(value);
    } else if (tmp->type == e_log) {
        buf2->value = log10(value);
    }
    for (; (count_shifts - index) != 0; count_shifts--) {
        buf2->next = buf->next;
        free(buf);
        buf = buf2->next;
    }
    buf2 = NULL;
    buf = NULL;
}
