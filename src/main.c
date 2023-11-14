#include "../inc/uls.h"

int main(int argc, char *argv[]) {
    int count = 1;
    t_uls_flags *uls_flags = mx_extr_flags_from_args(argv, &count);
    t_item **args = mx_create_name_list(argc, argv, count);

    int ex = uls_flags->ex;

    if (args) {
        mx_handle_dir_operation(&args, uls_flags);
    }

    free(uls_flags);
    uls_flags = NULL;

    exit(ex);
}
