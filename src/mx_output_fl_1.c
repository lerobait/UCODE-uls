#include "../inc/uls.h"

static void mx_print_name(t_item *name, t_uls_flags *uls_flags) {
    if (uls_flags->G != 1) {
        mx_printstr(name->name);
    }
    else {
        mx_printstr_fl_g(name);
    }
}

void mx_output_fl_1(t_item **names, t_uls_flags *uls_flags) {
    int i = 0;

    while (names[i]) {
        mx_print_name(names[i], uls_flags);
        mx_printchar('\n');
        i++;
    }
}
