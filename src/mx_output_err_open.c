#include "../inc/uls.h"

static void mx_output_error(t_item **args) {
    mx_printerr("uls: ");
    mx_printerr((*args)->path);
    mx_printerr(": ");
    mx_printerr((*args)->error);
    mx_printerr("\n");
}

static void mx_output_open(t_item **args, t_uls_flags *uls_flags) {
    mx_output_menu_with_flags(&(*args)->open, uls_flags, 1);

    if (uls_flags->R == 1) {
        uls_flags->files = 1;
        mx_del_files(&(*args)->open, uls_flags);

        if ((*args)->open) {
            mx_printchar('\n');
            mx_handle_dir_operation(&(*args)->open, uls_flags);
        }
    }
}

void mx_output_err_open(t_item **args, t_uls_flags *uls_flags) {
    if ((*args)->open != NULL) {
        mx_output_open(args, uls_flags);
    }
    else if ((*args)->error != NULL) {
        mx_output_error(args);
    }
}
