#include "main.h"
#include "check.h"
#include "hash.h"
#include <string.h>

START_TEST (test_base)
{
        ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(test_hash_init)
{
    struct HASH_HEAD *h = NULL;
    ck_assert_int_eq(1, hash_init(&h, 5, NULL));

    ck_assert(h != NULL);
    char *t = "test";
    ck_assert_int_eq(h->f(t), 1);

    //verify integrity of sllists
    struct SLL_NODE *tmp = NULL;
    char out = 1;
    for(int i = 0; i < 5; i++) {
        printf("LOOP: %d\n", i);
        tmp = h->a + i * sizeof(struct SLL_NODE);
        ck_assert_int_eq(1, sll_size(tmp));
        ck_assert_int_eq(sizeof(char), (int)tmp->d_size);
        memcpy(&out, tmp->d, sizeof(char));
        ck_assert_int_eq(out, 0);
        tmp = NULL;
    }
}
END_TEST

START_TEST(test_hash_add_get)
{
    struct HASH_HEAD *h = NULL;
    ck_assert_int_eq(1, hash_init(&h, 5, NULL));

    ck_assert_int_eq(1, hash_add(h, "test1"));
    ck_assert_int_eq(1, hash_locate(h, "test1"));

    ck_assert_int_eq(1, hash_add(h, "something"));
    ck_assert_int_eq(2, sll_size(h->a + sizeof(struct SLL_NODE)));
    ck_assert_int_eq(1, hash_locate(h, "something"));
}
END_TEST

Suite* str_suite (void) {
        Suite *suite = suite_create("HASH");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_base);
        tcase_add_test(tcase, test_hash_init);
        tcase_add_test(tcase, test_hash_add_get);
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