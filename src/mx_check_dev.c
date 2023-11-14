#include "../inc/uls.h"

bool mx_check_dev(t_item **names, t_size *sz) {
    bool is_dev = false;
    int i = 0;

    while (names[i]) {
        if (IS_BLOCK(names[i]->inf.st_mode) || IS_CHAR(names[i]->inf.st_mode)) {
            is_dev = true;
            break;
        }

        i++;
    }

    sz->dev = is_dev;
    return is_dev;
}
