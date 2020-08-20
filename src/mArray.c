#include "mArray.h"

//TODO: array destroy

int arr_init(struct DYN_ARR *arr, size_t u) {
    if(arr == NULL || arr->head != NULL || u <= 0) return 0;

    arr->head = malloc(u * DYN_ARR_START_SIZE);
    if(arr->head == NULL) return 0;
    memset(arr->head, 0x0, u * DYN_ARR_START_SIZE);

    arr->usize = u;
    arr->ind_num = DYN_ARR_START_SIZE;
    arr->curr_ind = -1;

    return 1;
}

int arr_add(struct DYN_ARR *arr, void *val, size_t ind) {
    if(arr == NULL || arr->head == NULL || val == NULL || ind > arr->ind_num || ind < 0) return 0;

    memcpy((arr->head + ind * arr->usize), val, arr->usize);

    return 1;
}

int arr_get(struct DYN_ARR *arr, size_t ind, void **holder) {
    if(arr == NULL || arr->head == NULL || ind > arr->ind_num || ind < 0 || *holder != NULL || holder == NULL) {
        *holder = NULL;   
        return 0;
    }

    *holder = malloc(arr->usize);
    if(*holder == NULL) return -1;

    memcpy(*holder, (arr->head + ind * arr->usize), arr->usize);
    return arr->usize;
}

int arr_resize(struct DYN_ARR *arr, size_t nSize) {
    if(arr == NULL || nSize < 0 || arr->head == NULL) return 0;

    arr->ind_num = nSize;
    arr->head = realloc(arr->head, arr->usize * arr->ind_num);

    return 1;
}

int arr_push(struct DYN_ARR *arr, void *val) {
    if(arr == NULL || arr->head == NULL || val == NULL) return 0;

    arr->curr_ind += 1;
    if(arr->curr_ind >= 2 *arr->ind_num / 2) {
        int resize_out = arr_resize(arr, 2 * arr->ind_num);
        if(resize_out < 1) return resize_out;
    }

    int out = arr_add(arr, val, arr->curr_ind);
    if(out <= 0) arr->curr_ind--;

    return out;
}

int arr_pop(struct DYN_ARR *arr, void **out) {
    if(arr == NULL || arr->head == NULL || out == NULL || *out != NULL) return 0;

    if(arr->curr_ind < 0) {
        *out = NULL;
        return arr->curr_ind;
    }

    int retVal = arr_get(arr, arr->curr_ind, out);
    if(retVal > 0 && arr->curr_ind > -1) arr->curr_ind--;

    return retVal;
}