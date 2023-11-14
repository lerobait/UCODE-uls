#include "../inc/uls.h"

static void mx_print_and_free_error(t_item *errors) {
    mx_printerr("uls: ");
    mx_printerr(errors->name);
    mx_printerr(": ");
    mx_printerr(errors->error);
    mx_printerr("\n");
    mx_strdel(&errors->name);
    mx_strdel(&errors->path);
    mx_strdel(&errors->error);
    free(errors);
}

void mx_output_errmessage(t_item ***errors, t_uls_flags *uls_flags) {
    if (errors && *errors && **errors) {
        mx_sort(errors, uls_flags);
        uls_flags->files = 1;
        uls_flags->ex = 1;
        int i = 0;

        while ((*errors)[i]) {
            mx_print_and_free_error((*errors)[i]);
            (*errors)[i] = NULL;
            i++;
        }

        free(*errors);
        *errors = NULL;
    }
}
