#include "main.h"
#include "check.h"
#include "nodeTree.h"
#include <string.h>
#include "hashmap.h"

START_TEST (test_base)
{
        ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(test_node_init)
{
        int i = 14;
        struct NODE_TREE *h = nodeTree_init(&i, sizeof(i), str_hash);

        //verify that hashmap is accessible
        ck_assert_int_eq(1, hashmap_add(h->params, "first key", "first val"));
        struct KEYVAL_PAIR *out = hashmap_locate(h->params, "first key");
        // printf("OUT: %s\n", ((struct KEYVAL_PAIR *)out)->val);
        ck_assert_int_eq(0, strcmp(((struct KEYVAL_PAIR *)out)->val, "first val"));

        char *a[] = {"first", "second", "third", "fourth", "fifth"};
        char *b[] = {"1", "2", "3", "4", "5"};
        for(int i = 0; i < 5; i++) {
                ck_assert_int_eq(1, hashmap_add(h->params, a[i], b[i]));
        }

        // hashmap_print(h->params);

        out = NULL;
        for(int i = 0; i < 5; i++) {
                out = hashmap_locate(h->params, a[i]);
                ck_assert_int_eq(0, strcmp(((struct KEYVAL_PAIR *)out)->val, b[i]));
                out = NULL;
        }

        for(int i = 4; i > -1; i--) {
                out = hashmap_locate(h->params, a[i]);
                ck_assert_int_eq(0, strcmp(((struct KEYVAL_PAIR *)out)->val, b[i]));
                out = NULL;
        }
}
END_TEST

START_TEST(test_nodeTree_manipulate_peers)
{
        struct NODE_TREE *head = NULL, *pNew = NULL;
        int i = 0;
        head = nodeTree_init(&i, sizeof(i), str_hash);
        ck_assert(NULL != head);
        ck_assert_int_eq(head->d_size, sizeof(int));
        ck_assert_int_eq(0, *(int *)head->data);
        for(i = 1; i < 10; i++) {
                pNew = nodeTree_init(&i, sizeof(i), str_hash);
                ck_assert(NULL != head);
                ck_assert_int_eq(1, nodeTree_push_peer(head, pNew));
                pNew = NULL;                    
        }

        ck_assert_int_eq(10, nodeTree_lvlSize(head));

        // nodeTree_print(head, 0b011);
        ck_assert_int_eq(1, nodeTree_destroy(&head));
        // nodeTree_print(head, 0b011);
}
END_TEST

START_TEST(test_nodeTree_manuipulate_children)
{
        int i = 0;
        struct NODE_TREE *head = nodeTree_init(&i, sizeof(i), str_hash), *pNew = NULL;
        ck_assert(NULL != head);
        ck_assert_int_eq(head->d_size, sizeof(int));
        ck_assert_int_eq(0, *(int *)head->data);
        for(i = 1; i < 10; i++) {
                pNew = nodeTree_init(&i, sizeof(i), str_hash);
                ck_assert(NULL != pNew);
                ck_assert_int_eq(1, nodeTree_push_peer(head, pNew));
                pNew = NULL;
        }

        //add one child to each node
        struct NODE_TREE *tmp = head;
        i = 11;
        while(tmp != NULL) {
                pNew = nodeTree_init(&i, sizeof(i), str_hash);
                ck_assert(NULL != pNew);
                ck_assert_int_eq(1, nodeTree_push_child(tmp, pNew));

                i++;
                tmp = tmp->next;
        }

        tmp = head;
        while(tmp != NULL) {
                struct NODE_TREE *child = tmp->child;
                ck_assert_int_eq(1, nodeTree_lvlSize(child));
                tmp = tmp->next;
        }

        pNew = NULL;
        pNew = nodeTree_init(&i, sizeof(i), str_hash);
        ck_assert(NULL != pNew);
        ck_assert_int_eq(1, nodeTree_push_child(head->child, pNew));

        // nodeTree_print(head, 0b011);
}
END_TEST

Suite* str_suite (void) {
        Suite *suite = suite_create("NODE_TREE");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_base);
        tcase_add_test(tcase, test_node_init);
        tcase_add_test(tcase, test_nodeTree_manipulate_peers);
        tcase_add_test(tcase, test_nodeTree_manuipulate_children);
        suite_add_tcase(suite, tcase);
        return suite;
}

int main (int argc, char *argv[]) {
        int number_failed;
        Suite *suite = str_suite();
        SRunner *runner = srunner_create(suite);
        //options are CK_FORK or CK_NOFORK, NOFORK allows for GDB use with unit tests
        srunner_set_fork_status(runner, CK_NOFORK);
        srunner_run_all(runner, CK_NORMAL);
        number_failed = srunner_ntests_failed(runner);
        srunner_free(runner);
        return number_failed;
}