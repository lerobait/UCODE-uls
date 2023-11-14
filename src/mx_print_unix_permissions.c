#include "../inc/uls.h"

static char mx_check_ch_mode(char chmod) {
    return (chmod == '-') ? 'S' : 's';
}

static char mx_check_ch_mode_2(char *chmod) {
    chmod[9] = (chmod[9] == '-') ? 'T' : 't';
    return chmod[9];
}

void mx_print_unix_permissions(t_item *print) {
    int i = 0;

    char chmod[12];
    
    chmod[0] = mx_check_unix_permissions(print);
    chmod[1] = (S_IRUSR & print->inf.st_mode) ? 'r' : '-';
    chmod[2] = (S_IWUSR & print->inf.st_mode) ? 'w' : '-';
    chmod[3] = (S_IXUSR & print->inf.st_mode) ? 'x' : '-';
    chmod[4] = (S_IRGRP & print->inf.st_mode) ? 'r' : '-';
    chmod[5] = (S_IWGRP & print->inf.st_mode) ? 'w' : '-';
    chmod[6] = (S_IXGRP & print->inf.st_mode) ? 'x' : '-';
    chmod[7] = (S_IROTH & print->inf.st_mode) ? 'r' : '-';
    chmod[8] = (S_IWOTH & print->inf.st_mode) ? 'w' : '-';
    chmod[9] = (S_IXOTH & print->inf.st_mode) ? 'x' : '-';
    chmod[10] = mx_get_acl(print);
    chmod[11] = '\0';
    S_ISUID & print->inf.st_mode ? chmod[3] = mx_check_ch_mode(chmod[3]) : 0;
    S_ISGID & print->inf.st_mode ? chmod[6] = mx_check_ch_mode(chmod[6]) : 0;
    S_ISVTX & print->inf.st_mode ? chmod[9] = mx_check_ch_mode_2(chmod) : 0;

    while (chmod[i]) {
        mx_printchar(chmod[i]);
        i++;
    }

    mx_printchar(' ');
}
