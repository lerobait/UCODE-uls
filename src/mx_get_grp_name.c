#include "../inc/uls.h"

void mx_get_grp_name(t_item *print, int grp) {
    struct group *grup = getgrgid(print->inf.st_gid);
    char *name = grup ? mx_strdup(grup->gr_name) : mx_itoa(print->inf.st_gid);
    int counter = mx_strlen(name);

    mx_printstr(name);

    for (int i = counter; i < grp; i++) {
        mx_printchar(' ');
    }
    
    mx_printstr("  ");
    free(name);
}
