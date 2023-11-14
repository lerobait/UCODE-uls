#include "../inc/uls.h"

t_uls_flags *mx_extr_flags_from_args(char *argv[], int *i) {
    t_uls_flags *uls_flags = malloc(sizeof(t_uls_flags));
    uls_flags->r = 1;

    while(argv[*i]) {
        if (argv[*i][0] != '-') {
            break;
        }

        if (argv[*i][1] == '-') {
            (*i)++;
            break;
        }

        if (argv[*i][1] == '\0') {
            break;
        }

        int j = 1;

        while (argv[*i][j]) {
            mx_set_flags_from_char(&uls_flags, argv[*i][j]);
            j++;
        }

        (*i)++;
    }

    return uls_flags;
}
