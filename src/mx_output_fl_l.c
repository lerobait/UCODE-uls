#include "../inc/uls.h"

static void mx_print_all_names(t_item **names, t_size *sz, t_uls_flags *uls_flags) {
    int i = 0;

    while (names[i]) {
        mx_print_all_details(names[i], sz, uls_flags);
        i++;
    }
}

static void mx_calc_block_size_and_count_size(t_item **names, t_size *sz, int *blk_sz) {
    int i = 0;

    while (names[i]) {
        *blk_sz += names[i]->inf.st_blocks;
        mx_count_sz(sz, names[i]);
        i++;
    }
}

void mx_output_fl_l(t_item **names, t_uls_flags *uls_flags, int flag) {
    int blk_sz = 0;
    t_size *sz = malloc(sizeof(t_size));

    mx_new_size(sz);
    mx_calc_block_size_and_count_size(names, sz, &blk_sz);

    if (flag == 1) {
        mx_printstr("total ");
        mx_printint(blk_sz);
        mx_printchar('\n');
    }

    mx_check_dev(names, sz);
    mx_print_all_names(names, sz, uls_flags);
    free(sz);
}
