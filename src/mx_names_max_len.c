#include "../inc/uls.h"

int mx_names_max_len(t_item **names) {
    int max = 0;
    int i = 0;

    while (names[i]) {
        int tmp = mx_strlen(names[i]->name);

        if (tmp > max) {
            max = tmp;
        }

        i++;
    }
    
    max += (max % 8 == 0) ? 8 : 8 - (max % 8);
    return max;
}
