#include "../inc/uls.h"

char mx_check_unix_permissions(t_item *print) {
    char type = '-';
    mode_t mode = print->inf.st_mode;

    if (IS_DIRECTORY(mode)) type = 'd';
    else if (IS_LINK(mode)) type = 'l';
    else if (IS_BLOCK(mode)) type = 'b';
    else if (IS_CHAR(mode)) type = 'c';
    else if (IS_FIFOFILE(mode)) type = 'p';
    else if (IS_SOCKET(mode)) type = 's';
    else if (IS_WHITEOUT(mode)) type = 'w';

    return type;
}
