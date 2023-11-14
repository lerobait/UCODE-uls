#include "../inc/uls.h"

void mx_set_secondary_flags(t_uls_flags **uls_flags, char flag) {
    switch (flag) {
        case 'S':
            (*uls_flags)->S = 1;
            break;

        case 'r':
            if ((*uls_flags)->r != -1)
                (*uls_flags)->r = 0;
            break;

        case 'G':
            if (!isatty(1))
                (*uls_flags)->G = 0;
            break;

        case 'R':
            (*uls_flags)->R = 1;
            break;

        case 'A':
            (*uls_flags)->A = 1;
            break;

        case 'g':
            (*uls_flags)->g = 1;
            (*uls_flags)->l = 1;
            break;

        case 'o':
            (*uls_flags)->o = 1;
            (*uls_flags)->l = 1;
            break;

        default:
            mx_process_output_flags(uls_flags, flag);
            break;
    }
}
