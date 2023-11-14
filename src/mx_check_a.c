#include "../inc/uls.h"

int mx_check_a(char *name, t_uls_flags *uls_flags) {
    return uls_flags->A == 1 && mx_strcmp(name, ".") != 0 && mx_strcmp(name, "..") != 0;
}
