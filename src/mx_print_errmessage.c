#include "../inc/uls.h"

static void mx_print_char_err(char c) {
    write(2, &c, 1);
}

void print_errmessage(char flag) {
    mx_printerr("uls: illegal option -- ");
    mx_print_char_err(flag);
    mx_printerr("\n");
    mx_printerr("usage: uls [-ACGRSTcfglmortux1] [file ...]\n");
}
