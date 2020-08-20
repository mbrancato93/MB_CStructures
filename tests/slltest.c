#include "main.h"
#include "check.h"
#include "sllist.h"
#include <string.h>

START_TEST (test_base)
{
        ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(sll_init_test)
{
        struct SLL_NODE *n = NULL;
        int i = 1;
        ck_assert_int_eq(1, sll_init_node(&n, &i, sizeof(int)));

        ck_assert_int_eq(1, *(int *)(n->d));
}
END_TEST

START_TEST(sll_size_add_tests)
{
        struct SLL_NODE *head = NULL;
        int i = 1;
        ck_assert_int_eq(1, sll_init_node(&head, &i, sizeof(i)));

        ck_assert(head != NULL);
        ck_assert_int_eq(1, sll_size(head));

        struct SLL_NODE *n = NULL;
        int j = 2;
        ck_assert_int_eq(1, sll_init_node(&n, &j, sizeof(j)));
        ck_assert_int_eq(1, sll_add_node(n, head));
        ck_assert_int_eq(2, *(int *)(head->next->d));
        ck_assert(NULL == head->next->next);
        ck_assert_int_eq(2, sll_size(head));

        struct SLL_NODE *in = NULL;
        int k = 3;
        ck_assert_int_eq(1, sll_init_node(&in, &k, sizeof(k)));
        ck_assert_int_eq(1, sll_add_node(in, head));
        ck_assert_int_eq(3, *(int *)(head->next->d));
        ck_assert(n == head->next->next);
        ck_assert_int_eq(2, *(int *)(head->next->next->d));
        ck_assert_int_eq(3, sll_size(head));
}
END_TEST

START_TEST(sll_remove_node_test)
{
        struct SLL_NODE *head = NULL;
        int i = 1;
        ck_assert_int_eq(1, sll_init_node(&head, &i, sizeof(i)));
        ck_assert_int_eq(1, sll_size(head));

        struct SLL_NODE *n1 = NULL;
        i = 2;
        ck_assert_int_eq(1, sll_init_node(&n1, &i, sizeof(i)));
        ck_assert_int_eq(1, sll_add_node(n1, head));
        ck_assert_int_eq(2, sll_size(head));

        struct SLL_NODE *n2 = NULL;
        i = 3;
        ck_assert_int_eq(1, sll_init_node(&n2, &i, sizeof(i)));
        ck_assert_int_eq(1, sll_add_node(n2, n1));
        ck_assert_int_eq(3, sll_size(head));

        struct SLL_NODE *n3 = NULL;
        i = 4;
        ck_assert_int_eq(1, sll_init_node(&n3, &i, sizeof(i)));
        ck_assert_int_eq(1, sll_add_node(n3, n2));
        ck_assert_int_eq(4, sll_size(head));

        struct SLL_NODE *out = NULL;
        ck_assert(head == sll_remove_node(head, n2, &out));
        ck_assert_int_eq(3, sll_size(head));
        ck_assert_int_eq(3, *(int *)(out->d));
        ck_assert_int_eq(1, *(int *)(head->d));
        ck_assert_int_eq(2, *(int *)(head->next->d));
        ck_assert_int_eq(4, *(int *)(head->next->next->d));
        ck_assert(NULL == head->next->next->next);
        free(out->d);
        free(out);
        out = NULL;

        ck_assert_int_eq(1, sll_destroy(head));
        head = NULL;
        ck_assert_int_eq(0, sll_size(head));
}
END_TEST

//TODO::ADD 100 list size
START_TEST(sll_add_X)
{
        struct SLL_NODE *head = NULL;
        int i = 0;
        sll_init_node(&head, &i, sizeof(i));
        struct SLL_NODE *tmp = NULL;
        i = 1;
        while( i < 100 ) {
                ck_assert_int_eq(1, sll_init_node(&tmp, &i, sizeof(i)));
                ck_assert(NULL != tmp);
                ck_assert_int_eq(1, sll_push_node(head, tmp));

                tmp = NULL;
                i++;
        }

        tmp = head;
        for(int j = 0; j < 100; j++) {
                ck_assert_int_eq(*(int *)tmp->d, j);
                tmp = tmp->next;
        }
        ck_assert_int_eq(100, sll_size(head));
        ck_assert_int_eq(1, sll_destroy(head));
        head = NULL;
        ck_assert_int_eq(0, sll_size(head));
}
END_TEST

START_TEST(sll_combine_test)
{
        struct SLL_NODE *head = NULL;
        int i = 0;
        ck_assert_int_eq(1, sll_init_node(&head, &i, sizeof(i)));
        struct SLL_NODE *tmp = NULL;
        i = 1;
        while(i < 10) {
                ck_assert_int_eq(1, sll_init_node(&tmp, &i, sizeof(i)));
                ck_assert(NULL != tmp);
                ck_assert_int_eq(1, sll_push_node(head, tmp));

                tmp = NULL;
                i++;
        }

        ck_assert_int_eq(10, sll_size(head));

        // i++;
        struct SLL_NODE *head2 = NULL;
        ck_assert_int_eq(1, sll_init_node(&head2, &i, sizeof(i)));
        i++;
        while(i < 20) {
                ck_assert_int_eq(1, sll_init_node(&tmp, &i, sizeof(i)));
                ck_assert(NULL != tmp);
                ck_assert_int_eq(1, sll_push_node(head2, tmp));

                tmp = NULL;
                i++;
        }

        ck_assert_int_eq(10, sll_size(head2));

        ck_assert_int_eq(1, sll_combine(head, head2));

        for(i = 0; i < 20; i++) {
                ck_assert(head != NULL);
                ck_assert_int_eq(i, *(int *)head->d);
                head = head->next;
        }

}
END_TEST

Suite* str_suite (void) {
        Suite *suite = suite_create("SLL");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_base);
        tcase_add_test(tcase, sll_init_test);
        tcase_add_test(tcase, sll_size_add_tests);
        tcase_add_test(tcase, sll_remove_node_test);
        tcase_add_test(tcase, sll_add_X);
        tcase_add_test(tcase, sll_combine_test);
        suite_add_tcase(suite, tcase);
        return suite;
}

int main (int argc, char *argv[]) {
        int number_failed;
        Suite *suite = str_suite();
        SRunner *runner = srunner_create(suite);
        srunner_run_all(runner, CK_NORMAL);
        number_failed = srunner_ntests_failed(runner);
        srunner_free(runner);
        return number_failed;
}