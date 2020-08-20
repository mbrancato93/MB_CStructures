#include "main.h"
#include "check.h"
#include "mArray.h"
#include <string.h>

START_TEST (test_base)
{
        ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST (test_init)
{
        struct DYN_ARR t;
        t.head = NULL;
        // int i = 1;
        ck_assert_int_eq(1, arr_init(&t, sizeof(int)));
        ck_assert(NULL != t.head);
}
END_TEST

START_TEST (test_add_get)
{
        struct DYN_ARR t;
        t.head = NULL;
        int i = 1;
        ck_assert_int_eq(1, arr_init(&t, sizeof(int)));
        ck_assert(NULL != t.head);

        ck_assert_int_eq(1, arr_add(&t, &i, 0));
        int *out = NULL;
        ck_assert_int_eq(sizeof(int), arr_get(&t, 0, (void **)&out));
        ck_assert(NULL != out);
        ck_assert_int_eq(1, *out);

        free(out);
        out = NULL;

        i = 11;
        ck_assert_int_eq(1, arr_add(&t, (void *)&i, 1));
        ck_assert_int_eq(sizeof(int), arr_get(&t, 1, (void **)&out));
        ck_assert(NULL != out);
        ck_assert_int_eq(11, *out);


        struct DYN_ARR ss;
        ss.head = NULL;
        struct HOLDTEST {
                int a;
                int b;
                int c;
        };
        struct HOLDTEST holdTest;
        holdTest.a = 10;
        holdTest.b = 15;
        holdTest.c = 17;
        ck_assert_int_eq(1, arr_init(&ss, sizeof(holdTest)));
        ck_assert(NULL != ss.head);
        ck_assert_int_eq(1, arr_add(&ss, &holdTest, 0));
        struct HOLDTEST *outSS = NULL;

        ck_assert_int_eq(sizeof(struct HOLDTEST), arr_get(&ss, 0, (void **)&outSS));
        ck_assert_int_eq(10, outSS->a);
        ck_assert_int_eq(15, outSS->b);
        ck_assert_int_eq(17, outSS->c);
        free(outSS);
}
END_TEST

START_TEST (test_resize)
{
        struct DYN_ARR t;
        t.head = NULL;
        ck_assert_int_eq(1, arr_init(&t, sizeof(int)));
        ck_assert(NULL != t.head);
        ck_assert_int_eq(DYN_ARR_START_SIZE, t.ind_num);
        ck_assert_int_eq(sizeof(int), t.usize);

        ck_assert_int_eq(1, arr_resize(&t, DYN_ARR_START_SIZE * 2));
        ck_assert_int_eq(DYN_ARR_START_SIZE * 2, t.ind_num);
}
END_TEST

START_TEST (test_push_pop_int)
{
        struct DYN_ARR t;
        t.head = NULL;
        ck_assert_int_eq(1, arr_init(&t, sizeof(int)));
        ck_assert(NULL != t.head);
        ck_assert_int_eq(-1, t.curr_ind);

        int i = 14;
        ck_assert_int_eq(1, arr_push(&t, (void *)&i));
        int *out = NULL;
        ck_assert_int_eq(sizeof(int), arr_get(&t, 0, (void **)&out));
        ck_assert_int_eq(14, *out);
        ck_assert_int_eq(0, t.curr_ind);
        free(out);
        out = NULL;

        i = 17;
        ck_assert_int_eq(1, arr_push(&t, (void *)&i));
        ck_assert_int_eq(1, t.curr_ind);
        ck_assert_int_eq(sizeof(int), arr_pop(&t, (void **)&out));
        ck_assert_int_eq(17, *out);
        ck_assert_int_eq(0, t.curr_ind);

        free(out);
        out = NULL;

        ck_assert_int_eq(sizeof(int), arr_pop(&t, (void **)&out));
        ck_assert_int_eq(-1, t.curr_ind);
        ck_assert_int_eq(14, *out);

        free(out);
        out = NULL;
}
END_TEST

START_TEST (test_push_pop_struct)
{
        struct DYN_ARR t;
        t.head = NULL;

        struct TEST_STRUCT {
                int a;
                int b;
                int c;
        };

        struct TEST_STRUCT testStruct;
        testStruct.a = 1;
        testStruct.b = 5;
        testStruct.c = 17;

        ck_assert_int_eq(1, arr_init(&t, sizeof(struct TEST_STRUCT)));
        ck_assert(NULL != t.head);
        ck_assert_int_eq(-1, t.curr_ind);

        ck_assert_int_eq(1, arr_push(&t, (void *)&testStruct));
        struct TEST_STRUCT *out = NULL;
        ck_assert_int_eq(sizeof(struct TEST_STRUCT), arr_get(&t, 0, (void **)&out));
        ck_assert_int_eq(out->a, 1);
        ck_assert_int_eq(out->b, 5);
        ck_assert_int_eq(out->c, 17);

        free(out);
        out = NULL;

        testStruct.a = 10;
        testStruct.b = 11;
        testStruct.c = 12;
        ck_assert_int_eq(1, arr_push(&t, (void *)&testStruct));
        ck_assert_int_eq(sizeof(struct TEST_STRUCT), arr_pop(&t, (void **)&out));
        ck_assert_int_eq(out->a, 10);
        ck_assert_int_eq(out->b, 11);
        ck_assert_int_eq(out->c, 12);
        free(out);
        out = NULL;

        ck_assert_int_eq(sizeof(struct TEST_STRUCT), arr_pop(&t, (void **)&out));
        ck_assert_int_eq(out->a, 1);
        ck_assert_int_eq(out->b, 5);
        ck_assert_int_eq(out->c, 17);
}
END_TEST

START_TEST (test_push_pop_30x)
{
        struct DYN_ARR t;
        t.head = NULL;
        ck_assert_int_eq(1, arr_init(&t, sizeof(int)));
        ck_assert(NULL != t.head);

        int i = 0;
        while( i < 30 ) {
                ck_assert_int_eq(1, arr_push(&t, (void *)&i));
                // printf("%d\n", i);
                i++;
        }

        ck_assert_int_eq(40, t.ind_num);

        int j = t.curr_ind;
        int *out = NULL;
        while(t.curr_ind > -1) {
                ck_assert_int_eq(sizeof(int), arr_pop(&t, (void **)&out));
                ck_assert_int_eq(j, *out);
                free(out);
                out = NULL;
                j--;
        }
}
END_TEST

Suite* str_suite (void) {
        Suite *suite = suite_create("M_ARRAY");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_base);
        tcase_add_test(tcase, test_init);
        tcase_add_test(tcase, test_add_get);
        tcase_add_test(tcase, test_resize);
        tcase_add_test(tcase, test_push_pop_int);
        tcase_add_test(tcase, test_push_pop_struct);
        tcase_add_test(tcase, test_push_pop_30x);
        suite_add_tcase(suite, tcase);
        return suite;
}

int main (int argc, char *argv[]) {
        int number_failed;
        Suite *suite = str_suite();
        SRunner *runner = srunner_create(suite);
        //options are CK_FORK or CK_NOFORK, NOFORK allows for GDB use with unit tests
        // srunner_set_fork_status(runner, CK_NOFORK);
        srunner_run_all(runner, CK_NORMAL);
        number_failed = srunner_ntests_failed(runner);
        srunner_free(runner);
        return number_failed;
}