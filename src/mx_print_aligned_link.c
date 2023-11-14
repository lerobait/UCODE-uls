#include "../inc/uls.h"

void mx_print_aligned_link(t_item *print, t_size *sz) {
    char *res_now = mx_itoa(print->inf.st_nlink);
    char *res_lnk = mx_itoa(sz->link);

    int spaces = mx_strlen(res_lnk) - mx_strlen(res_now);

    for (int i = 0; i < spaces; i++) {
        mx_printchar(' ');
    }

    mx_printint(print->inf.st_nlink);
    mx_printchar(' ');

    free(res_now);
    free(res_lnk);
}
