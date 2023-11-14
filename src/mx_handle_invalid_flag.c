#include "../inc/uls.h"

void mx_handle_invalid_flag(t_uls_flags **uls_flags, char flag) {
    print_errmessage(flag);
    free(*uls_flags);
    *uls_flags = NULL;
    exit(1);
}
