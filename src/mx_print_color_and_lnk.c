#include "../inc/uls.h"

static void mx_print_sym_link(t_item *print) {
    ssize_t buff_sz = print->inf.st_size == 0 ? 100 : print->inf.st_size + 1;
    char *buff = mx_strnew(buff_sz);

    if (buff) {
        ssize_t n_bytes = readlink(print->path, buff, buff_sz);

        if (n_bytes >= 0) {
            mx_printstr(" -> ");
            mx_printstr(buff);
        }

        mx_strdel(&buff);
    }
}

void mx_print_color_and_lnk(t_item *print, t_uls_flags *uls_flags) {
    if (uls_flags->G == 1) {
        mx_printstr_fl_g(print);
    } 
    else {
        mx_printstr(print->name);

        if (IS_LINK(print->inf.st_mode)) {
            mx_print_sym_link(print);
        }
    }
}
