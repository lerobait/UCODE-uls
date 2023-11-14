#include "../inc/uls.h"

void mx_print_sz(t_item *print, t_size *sz) {
    char *res_now = mx_itoa(print->inf.st_size);
    char *res_sz = mx_itoa(sz->size);
    int counter = mx_strlen(res_now);

    if (counter < mx_strlen(res_sz)) {
        for (; counter != mx_strlen(res_sz); counter++) {
            mx_printchar(' ');
        }
    }
    mx_print_double_cases(print, sz);
    mx_printchar(' ');
    free(res_now);
    free(res_sz);
}
