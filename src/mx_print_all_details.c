#include "../inc/uls.h"

static void mx_print_user_or_group_name(t_item *print, t_size *sz, t_uls_flags *uls_flags) {
    if (uls_flags->l == 1) {
        if (uls_flags->g == 0) {
            mx_get_usr_name(print, sz->user);
        }

        if (uls_flags->o == 0) {
            mx_get_grp_name(print, sz->group);
        }
    }
}

void mx_print_all_details(t_item *print, t_size *sz, t_uls_flags *uls_flags) {
    time_t *t = &print->inf.st_mtime;

    if (uls_flags->u == 1) {
        t = &print->inf.st_atime;
    }

    if (uls_flags->c == 1) {
        t = &print->inf.st_ctime;
    }

    mx_print_unix_permissions(print);
    mx_print_aligned_link(print, sz);
    mx_print_user_or_group_name(print, sz, uls_flags);
    mx_print_sz(print, sz);
    mx_new_time(print, ctime(t), uls_flags);
    mx_print_color_and_lnk(print, uls_flags);
    mx_printchar('\n');
}
