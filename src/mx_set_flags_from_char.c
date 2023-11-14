#include "../inc/uls.h"

void mx_set_flags_from_char(t_uls_flags **uls_flags, char flag) {
    switch (flag) {
        case 'T':
            (*uls_flags)->T = 1;
            break;

        case 'G':
            if (isatty(1))
                (*uls_flags)->G = 1;
            break;

        case 'c':
            (*uls_flags)->u = 0;
            (*uls_flags)->c = 1;
            break;

        case 't':
            (*uls_flags)->t = 1;
            break;

        case 'u':
            (*uls_flags)->u = 1;
            (*uls_flags)->c = 0;
            break;

        default:
            mx_set_secondary_flags(uls_flags, flag);
            break;
    }
}
