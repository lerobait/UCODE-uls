#include "../inc/uls.h"

static void mx_print_n(int *len) {
    (*len) = 0;
    mx_printchar('\n');
}

static void mx_print_names(t_item **names, int colm_width, t_uls_flags *uls_flags) {
    int len = 0;
    int next_len = 0;
    int i = 0;

    while (names[i]) {
        if (uls_flags->G == 1) {
            mx_printstr_fl_g(names[i]);
        }
        else {
            mx_printstr(names[i]->name);
        }

        len += mx_strlen(names[i]->name) + 2;

        if (names[i + 1]) {
            mx_printstr(", ");
            next_len = names[i + 2] ? 3 : 1;

            if (len + next_len + mx_strlen(names[i + 1]->name) > colm_width) {
                mx_print_n(&len);
            }
        }

        i++;
    }

    mx_printchar('\n');
}

void mx_output_fl_m(t_item **names, t_uls_flags *uls_flags) {
    struct winsize win;
    int colm_width = 80;

    if (!names) {
        return;
    }

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    if (isatty(1)) {
        colm_width = win.ws_col;
    }

    mx_print_names(names, colm_width, uls_flags);
}
