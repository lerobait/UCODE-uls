#include "../inc/uls.h"

void mx_print_tab(int len, int max_len) {
    int p = max_len - len;
    int count = (p % 8 != 0) ? (p / 8) + 1 : p / 8;

    int i = 0;
    
    while (i < count) {
        mx_printchar('\t');
        i++;
    }
}
