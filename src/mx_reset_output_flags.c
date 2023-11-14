#include "../inc/uls.h"

void mx_reset_output_flags(t_uls_flags **uls_flags) {
    (*uls_flags)->x = 0;
    (*uls_flags)->l = 0;
    (*uls_flags)->C = 0;
    (*uls_flags)->m = 0;
    (*uls_flags)->force = 0;
}
