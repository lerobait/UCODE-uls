#include "../inc/uls.h"

t_item *mx_make_item_node(char *data) {
    t_item *node = (t_item *)malloc(1 * sizeof(t_item));

    if (node) {
        node->name = mx_strdup(data);
        node->path = mx_strdup(data);
        node->error = NULL;

        if (lstat(data, &(node->inf)) == -1) {
            node->error = mx_strdup(strerror(errno));	
        }

        node->open = NULL;
    }

    return node;
}
