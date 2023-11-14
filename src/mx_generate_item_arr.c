#include "../inc/uls.h"

t_item **mx_generate_item_arr(char **name, int count) {
    int j = 0;
    t_item **items = malloc(count * sizeof(t_item *));

    while (name[j]) {
        items[j] = mx_make_item_node(name[j]);
        j++;
    }

    items[j] = NULL;
    return items;
}
