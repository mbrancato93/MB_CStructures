#include "main.h"
#include "check.h"
#include "hashmap.h"
#include <string.h>

START_TEST (test_base)
{
        ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(test_hashmap_init)
{
    struct HASHMAP_HEAD *h = hashmap_init(5, NULL);
    ck_assert(NULL != h);

    for(int i = 0; i < 5; i++) {
        ck_assert(NULL == h->a[i].d);
    }
}
END_TEST

START_TEST(test_hashmap_add_get)
{
    struct HASHMAP_HEAD *h = hashmap_init(7, str_hash);
    ck_assert(NULL != h);

    struct KEYVAL_PAIR pD[] = {
        {"first word", "first val"},
        {"second word", "second val"},
        {"another one", "another val"},
        {"this is it", "cool"},
        {"whatever", "yeah"},
        {"test1", "test2"},
        {"yes", "no"}
    };

    for(int i = 0; i < 7; i++) {
        printf("ADD: %d\n", i);
        ck_assert_int_eq(1, hashmap_add(h, pD[i].key, pD[i].val));
    }

    hashmap_print(h);

    void *outStr = NULL;
    for(int i = 0; i < 7; i++) {
        outStr = hashmap_locate(h, pD[i].key);
        ck_assert(NULL != outStr);
        ck_assert_int_eq(0, strcmp(pD[i].val, ((struct KEYVAL_PAIR *)outStr)->val));
        outStr = NULL;
    }
}
END_TEST

START_TEST(test_hashmap_remove_node)
{
    struct HASHMAP_HEAD *h = hashmap_init(7, str_hash);
    ck_assert(NULL != h);

    //add 10 nodes
    int i = 0;
    while( i < 10 ) {
        char si[5];
        sprintf(si, "%d", i);
        ck_assert_int_eq(1, hashmap_add(h, si, si));
        i++;
    }

    //locate all added values
    i = 0;
    while( i < 10 ) {
        char si[5];
        sprintf(si, "%d", i);
        ck_assert(NULL != hashmap_locate(h, si));
        i++;
    }

    hashmap_print(h);
    ck_assert_int_eq(10, hashmap_size(h));

    struct KEYVAL_PAIR *out = NULL;

    for(int i = 0; i < 10; i++) {
        char si[10];
        sprintf(si, "%d", i);
        struct SLL_NODE *o = hashmap_removeNode(h, si, &out);
        ck_assert_int_eq(0, strcmp(out->key, si));
        ck_assert_int_eq(0, strcmp(out->val, si));
        if(o != NULL) ck_assert(o->next == NULL);
        
        free((void *)out->key);
        free((void *)out->val);
        out->key = NULL;
        out->val = NULL;
        free(out);
        out = NULL;
    }

    hashmap_print(h);
    ck_assert_int_eq(0, hashmap_size(h));
}
END_TEST

START_TEST(test_hashmap_destroy)
{
    struct HASHMAP_HEAD *h = hashmap_init(10, str_hash);
    ck_assert(h != NULL);

    //add 10 nodes
    int i = 0;
    while( i < 10 ) {
        char si[5];
        sprintf(si, "%d", i);
        ck_assert_int_eq(1, hashmap_add(h, si, si));
        i++;
    }

    //locate all added values
    i = 0;
    while( i < 10 ) {
        char si[5];
        sprintf(si, "%d", i);
        ck_assert(NULL != hashmap_locate(h, si));
        i++;
    }

    hashmap_print(h);
    ck_assert_int_eq(10, hashmap_size(h));

    ck_assert_int_eq(10, hashmap_destroy(h));
    ck_assert_int_eq(0, hashmap_size(h));
}
END_TEST

Suite* str_suite (void) {
        Suite *suite = suite_create("HASHMAP");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_base);
        tcase_add_test(tcase, test_hashmap_init);
        tcase_add_test(tcase, test_hashmap_add_get);
        tcase_add_test(tcase, test_hashmap_remove_node);
        tcase_add_test(tcase, test_hashmap_destroy);
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