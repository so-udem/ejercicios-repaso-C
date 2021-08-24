#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "../src/maximo.h"

/**
START_TEST (test_name)
{
  // unit test code 
}
END_TEST
*/

START_TEST(test_maximo_create)
{
    ck_assert_int_eq(maximo(4, 10), 10);    
}
END_TEST


Suite * maximo_suite(void) {
    Suite *s;
    TCase *tc_core;   
    
    /* Core test case */
    s = suite_create("Maximo");
    tc_core = tcase_create("Core");


    tcase_add_test(tc_core, test_maximo_create);   
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = maximo_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}