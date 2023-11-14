#include "../inc/uls.h"

void mx_new_time(t_item *print, char *t, t_uls_flags *uls_flags) {
    int i = 4;

    if (uls_flags->T == 1) {
        while (t[i]) {
            mx_printchar(t[i++]);
        }
    } 
    else {
        if (1565913600 >= print->inf.st_mtime) {
            while (i < 10) {
                mx_printchar(t[i++]);
            }

            mx_printstr("  ");
            i = 20;

            while (i < 24) {
                mx_printchar(t[i++]);
            }
        } 
        else {
            while (i < 16) {
                mx_printchar(t[i++]);
            }
        }
    }

    mx_printstr(" ");
}
