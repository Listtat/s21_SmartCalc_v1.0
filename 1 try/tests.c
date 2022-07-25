#include <check.h>
#include "s21_smart_calc_1.0.h"

START_TEST(test_1) {
    double res = 0.0;
    char *str = "sin(cos(111))+tan(sqrt(222))-acos(asin(333))*atan(444)/ln(log(555))";
    char *value_of_x_str = "0.0";
    int result = calculator(str, value_of_x_str, &res);

    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_2) {
    double res = 0.0;
    char *str = "2/1+2+3+4*5*6^7-727mod728+((1000+500*2)*201)+sin(1)";
    char *value_of_x_str = "0.0";
    int result = calculator(str, value_of_x_str, &res);

    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_3) {
    double res = 0.0;
    char *str = "x+2/1+2+3+4*5*6^7-727";
    char *value_of_x_str = "0.0";
    int result = calculator(str, value_of_x_str, &res);

    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_4) {
    double res = 0.0;
    char *str = "x+2/1+2+3+x*x";
    char *value_of_x_str = "5.0";
    int result = calculator(str, value_of_x_str, &res);

    ck_assert_int_eq(result, 0);
}
END_TEST

int main() {
    Suite *s1 = suite_create("SmartCalc: ");
    TCase *tc1_1 = tcase_create("SmartCalc: ");
    SRunner *sr = srunner_create(s1);
    int result;
    suite_add_tcase(s1, tc1_1);

    tcase_add_test(tc1_1, test_1);
    tcase_add_test(tc1_1, test_2);
    tcase_add_test(tc1_1, test_3);
    tcase_add_test(tc1_1, test_4);

    srunner_run_all(sr, CK_ENV);
    result = srunner_ntests_failed(sr);
    srunner_free(sr);
    return result == 0 ? 0 : 1;
}

