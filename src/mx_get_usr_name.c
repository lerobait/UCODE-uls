#include "../inc/uls.h"

void mx_get_usr_name(t_item *print, int usr) {
    struct passwd *pw = getpwuid(print->inf.st_uid);
    char *name = NULL;

    if (pw) {
        name = mx_strdup(pw->pw_name);
    }
    else {
        name = mx_itoa(print->inf.st_uid);
    }

    int name_len = mx_strlen(name);
    mx_printstr(name);

    if (name_len < usr) {
        for (int i = name_len; i < usr; i++) {
            mx_printchar(' ');
        }
    }

    mx_printstr("  ");
    free(name);
}
