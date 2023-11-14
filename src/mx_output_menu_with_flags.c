#include "../inc/uls.h"

void mx_output_menu_with_flags(t_item ***names, t_uls_flags *uls_flags, int flag) {
    if (**names == NULL) {
        return;
    }

    mx_sort(&(*names), uls_flags);

    if (uls_flags->l) {
        mx_output_fl_l(*names, uls_flags, flag);
    }

    if (uls_flags->C == 1 && !uls_flags->G) {
        mx_output_fl_c(*names);
    }

    if (uls_flags->x == 1 && !uls_flags->G) {
        mx_output_fl_x(*names);
    }

    if (uls_flags->m == 1) {
        mx_output_fl_m(*names, uls_flags);
    }

    if (uls_flags->force == 1) {
        mx_output_fl_1(*names, uls_flags);
    }

    if (uls_flags->G == 1 && uls_flags->m != 1 && uls_flags->l != 1 && uls_flags->force != 1) {
        mx_output_fl_g(*names, uls_flags);
    }

    if (uls_flags->l != 1 && uls_flags->C != 1 && uls_flags->x != 1 && uls_flags->m != 1
        && uls_flags->force != 1 && !uls_flags->G && !uls_flags->g && !uls_flags->o && isatty(1)) {
        mx_output_fl_c(*names);
    }

    if (!isatty(1) && uls_flags->C != 1 && uls_flags->x != 1 && uls_flags->m != 1
        && uls_flags->l != 1 && uls_flags->g != 1 && uls_flags->o != 1 && uls_flags->force != 1) {
        mx_output_fl_1(*names, uls_flags);
    }
}
