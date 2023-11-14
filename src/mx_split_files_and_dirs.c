#include "../inc/uls.h"

void mx_split_files_and_dirs(t_item **args, t_type *number, t_item ***files, t_item ***dirs) {
    if (!IS_DIRECTORY((*args)->inf.st_mode)) {
        (*files)[number->s_f++] = mx_new_file_node((*args));
        (*files)[number->s_f] = NULL;
    }
    else {
        (*dirs)[number->s_d++] = mx_new_file_node((*args));
        (*dirs)[number->s_d] = NULL;
    }
}
