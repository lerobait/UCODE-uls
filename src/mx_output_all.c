#include "../inc/uls.h"

static void mx_print_path(t_item ***args, int i) {
    if ((*args)[i]->path[0] == '/' && (*args)[i]->path[1] == '/') {
        mx_printstr(&(*args)[i]->path[1]);
    }
    else {
        mx_printstr((*args)[i]->path);
    }

    mx_printchar(':');
    mx_printchar('\n');
}


void mx_out_put_all(t_item ***args, t_uls_flags *uls_flags) {
    if (*args) {
        int i = 0;

        while ((*args)[i] != NULL) {
            if (uls_flags->files == 1) {
                mx_print_path(args, i);
            }

            mx_output_err_open(&(*args)[i], uls_flags);

            if (uls_flags->files == 1 && (*args)[i+1]) {
                mx_printchar('\n');
            }

            i++;
        }

        mx_del_double_arr(args);
    }
}
