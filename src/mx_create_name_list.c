#include "../inc/uls.h"

t_item **mx_create_name_list(int argc, char **argv, int i) {
    int count = 0;
    char **name = mx_dup_args(argc, argv, i, &count);
    t_item **args = mx_generate_item_arr(name, count);

    mx_del_strarr(&name);
    return args;
}
