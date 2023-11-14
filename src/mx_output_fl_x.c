#include "../inc/uls.h"

static int mx_calc_num(t_item **names) {
    int num = 0;

    while(names[num]) {
        num++;
    }

    return num;
}

static void mx_print_row(t_item **names, int cols, int max_len) {
    int j = 0;

    while (names[j] && j < cols) {
        mx_printstr(names[j]->name);

        if (names[j + 1] && (j != cols - 1)) {
            mx_print_tab(mx_strlen(names[j]->name), max_len);
        }

        j++;
    }
}

static void mx_print_names_in_cols(t_item **names, int rows, int cols, int max_len) {
    int tmp_cols = cols;
    int i = 0;

    while (i < rows) {
        mx_print_row(names, cols, max_len);

        if (i != rows - 1) {
            mx_printchar('\n');
        }

        cols += tmp_cols;
        i++;
    }
}

static void mx_print_names_in_row(t_item **names, int max_len) {
    int i = 0;

    while (names[i]) {
        mx_printstr(names[i]->name);

        if (names[i + 1]) {
            mx_print_tab(mx_strlen(names[i]->name), max_len);
        }

        i++;
    }

    mx_printchar('\n');
}

static void mx_print_names(t_item **names, int max_len, int colm) {
    int rows;
    int cols = (colm / max_len) != 0 ? colm / max_len : 1;
    int num = mx_calc_num(names);

    if (max_len * cols > colm && cols != 1) {
        cols--;
    }

    if (num * max_len > colm) {
        rows = num / cols;

        if (rows == 0 || num % cols != 0) {
            rows += 1;
        }

        mx_print_names_in_cols(names, rows, cols, max_len);
    }
    else {
        mx_print_names_in_row(names, max_len);
    }
}

void mx_output_fl_x(t_item **names) {
    if (!names) {
        return;
    }

    int max_len = mx_names_max_len(names);
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    int colm = isatty(1) ? win.ws_col : 80;
    mx_print_names(names, max_len, colm);
}
