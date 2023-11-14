#include "../inc/uls.h"

static t_item *mx_create_file_node(t_item *arg) {
    t_item *node = (t_item *)malloc(sizeof(t_item));

    node->name = mx_strdup(arg->name);
    node->path = mx_strdup(arg->path);
    node->error = arg->error ? mx_strdup(arg->error) : NULL;
    lstat(node->path, &(node->inf));
    node->open = arg->open;

    return node;
}

static bool mx_is_directory(t_item *arg) {
    return arg->error == NULL && 
           IS_DIRECTORY(arg->inf.st_mode) && 
           mx_strcmp(arg->name, ".") != 0 &&
           mx_strcmp(arg->name, "..") != 0;
}

static void mx_create_fde(t_item ***dirs, t_item ***args) {
    int n_dir = 0;
    int i = 0;

    while ((*args)[i] != NULL) {
        if (mx_is_directory((*args)[i])) {
            n_dir++;
        }

        i++;
    }

    if (n_dir > 0) {
        *dirs = malloc((n_dir + 1) * sizeof(t_item *));
    }
}

static bool mx_is_valid_dir(t_item *arg) {
    return IS_DIRECTORY(arg->inf.st_mode) && 
           mx_strcmp(arg->name, ".") != 0 && 
           mx_strcmp(arg->name, "..") != 0;
}

static void mx_create_dir_node(t_item ***dirs, t_item *arg, int *n_dir) {
    (*dirs)[(*n_dir)++] = mx_create_file_node(arg);
    (*dirs)[*n_dir] = NULL;
}

void mx_del_files(t_item ***args, t_uls_flags *uls_flags) {
    t_item **dirs = NULL;
    int n_dir = 0;
    int i = 0;

    mx_create_fde(&dirs, args);

    while ((*args)[i] != NULL) {
        if ((*args)[i]->error == NULL && mx_is_valid_dir((*args)[i])) {
            mx_create_dir_node(&dirs, (*args)[i], &n_dir);
        }

        i++;
    }

    uls_flags->files = 1;
    mx_clear_item_arr(args, dirs);
}
