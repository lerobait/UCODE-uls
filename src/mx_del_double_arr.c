#include "../inc/uls.h"

void mx_del_double_arr(t_item ***args) {
    t_item **del_arr = *args;
    int i = 0;

    while (del_arr[i] != NULL) {
        mx_strdel(&del_arr[i]->name);
        mx_strdel(&del_arr[i]->path);

        if (del_arr[i]->error) {
            mx_strdel(&del_arr[i]->error);
        }

        if (del_arr[i]->open != NULL) {
            mx_del_double_arr(&del_arr[i]->open);
        }

        free(del_arr[i]);
        del_arr[i] = NULL;
        i++;
    }

    free(*args);
    *args = NULL;
}
