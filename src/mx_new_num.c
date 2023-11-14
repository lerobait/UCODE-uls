#include "../inc/uls.h"

t_type *mx_new_num() {
    t_type *num = malloc(sizeof (t_type));

    num->i = 0;
    num->s_f = 0;
    num->s_d = 0;
    num->s_e = 0;
    return num;
}
