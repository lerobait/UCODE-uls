#include "../inc/uls.h"

static void mx_free_item(t_item *item) {
    mx_strdel(&item->name);
    mx_strdel(&item->path);

    if (item->error) {
        mx_strdel(&item->error);
    }

    free(item);
}

void mx_clear_item_arr(t_item ***args, t_item **dirs) {
    t_item **del_arr = *args;
    int i = 0;

    while (del_arr[i] != NULL) {
        mx_free_item(del_arr[i]);
        del_arr[i] = NULL;
        i++;
    }

    free(*args);
    *args = dirs;
}
