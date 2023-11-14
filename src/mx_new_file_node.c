#include "../inc/uls.h"

t_item *mx_new_file_node(t_item *arg) {
    t_item *node = (t_item *)malloc(sizeof(t_item));

    node->name = mx_strdup(arg->name);
    node->path = mx_strdup(arg->path);
    node->error = arg->error ? mx_strdup(arg->error) : NULL;
    lstat(node->path, &(node->inf));
    node->open = arg->open ? arg->open : NULL;

    return node;
}
