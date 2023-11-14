#include "../inc/uls.h"

void mx_process_output_flags(t_uls_flags **uls_flags, char flag) {
    mx_reset_output_flags(uls_flags);
    
    switch (flag) {
        case 'l':
            (*uls_flags)->l = 1;
            break;

        case 'C':
            (*uls_flags)->C = 1;
            break;

        case '1':
            (*uls_flags)->force = 1;
            break;

        case 'x':
            (*uls_flags)->x = 1;
            break;

        case 'm':
            (*uls_flags)->m = 1;
            break;

        default:
            mx_handle_invalid_flag(uls_flags, flag);
            break;
    }
}
