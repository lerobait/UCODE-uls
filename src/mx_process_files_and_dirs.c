#include "../inc/uls.h"

t_item **mx_process_files_and_dirs(t_item ***args, t_uls_flags *uls_flags) {
    t_item **files = NULL;
    t_item **dirs = NULL;
    t_item **errors = NULL;
    t_type *num = mx_new_num();

    mx_sort_and_allocate_args(&files, &dirs, &errors, args);

    while ((*args)[num->i] != NULL) {
        if ((*args)[num->i]->error == NULL) {
            mx_split_files_and_dirs(&(*args)[num->i], num, &files, &dirs);
        }
        else {
            errors[num->s_e++] = mx_new_file_node((*args)[num->i]);
            errors[num->s_e] = NULL;
        }

        num->i++;
    }

    if (num->s_d > 1) {
        uls_flags->files = 1;
    }

    mx_clear_item_arr(args, dirs);
    mx_output_errmessage(&errors, uls_flags);
    free(num);
    return files;
}
