#include "../inc/uls.h"

void mx_handle_dir_operation(t_item ***args, t_uls_flags *uls_flags) {

    if (!args || !*args || !uls_flags) {
        return;
    }

    t_item **files = mx_process_files_and_dirs(args, uls_flags);

    if (files) {
        mx_output_menu_with_flags(&files, uls_flags, 0);

        if (*args) {
            mx_printchar('\n');
        }

        uls_flags->files = 1;
        mx_del_double_arr(&files);
    }

    open_dir(args, uls_flags);
}
