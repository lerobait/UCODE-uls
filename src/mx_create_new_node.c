#include "../inc/uls.h"

t_item *mx_create_new_node(char *name, char *path) {
    t_item *node = (t_item *)malloc(sizeof(t_item));

    if (node == NULL) {
        return NULL;
    }

    node->name = mx_strdup(name);

    if (node->name == NULL) {
        free(node);
        return NULL;
    }

    node->path = mx_strdup(path);

    if (node->path == NULL) {
        free(node->name);
        free(node);
        return NULL;
    }

    mx_join(&node->path, "/");
    mx_join(&node->path, name);
    node->error = NULL;

    if (lstat(node->path, &(node->inf)) == -1) {
        node->error = mx_strdup(strerror(errno));

        if (node->error == NULL) {
            free(node->path);
            free(node->name);
            free(node);
            return NULL;
        }
    }

    node->open = NULL;
    return node;
}
