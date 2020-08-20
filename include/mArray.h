#ifndef __MARRAY_H__
#define __MARRAY_H__

#include "main.h"

#define DYN_ARR_START_SIZE 10

struct DYN_ARR {
    void *head;
    size_t usize;
    size_t ind_num;
    int curr_ind;
};

int arr_init(struct DYN_ARR *arr, size_t u);
int arr_add(struct DYN_ARR *arr_head, void *val, size_t ind);
int arr_get(struct DYN_ARR *arr, size_t ind, void **holder);
int arr_resize(struct DYN_ARR *arr, size_t nSize);
int arr_push(struct DYN_ARR *arr, void *val);
int arr_pop(struct DYN_ARR *arr, void **out);

#endif