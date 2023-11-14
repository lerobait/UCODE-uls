#include "../inc/uls.h"

static int mx_max_len_fl_g(t_item **names) {
    int max = 0;
    int i = 0;

    while (names[i]) {
        int tmp = mx_strlen(names[i]->name);

        if (tmp > max) {
            max = tmp;
        }

        i++;
    }

    return max + 1;
}

static void mx_print_spaces_fl_g(int len, int max_len) {
    int count = max_len - len;
    int i = 0;

    while (i < count) {
        mx_printchar(' ');
        i++;
    }
}

static void mx_print_row_fl_g(t_item **names, int max_len) {
    int i = 0;

    while (names[i]) {
        mx_printstr_fl_g(names[i]);

        if (names[i + 1]) {
            int spaces = mx_strlen(names[i]->name);
            mx_print_spaces_fl_g(spaces, max_len);
        }

        i++;
    }
}

static void mx_print_names_in_cols_a(t_item **names, int row_count, int col_count, int max_len) {
    int name_index = 0;
    int col_count_tmp = col_count;
    int row_index = 0;

    while (row_index < row_count) {
        while (names[name_index] && name_index < col_count) {

            mx_printstr_fl_g(names[name_index]);

            if (names[name_index + 1] && (name_index != col_count - 1)) {
                mx_print_spaces_fl_g(mx_strlen(names[name_index]->name), max_len);
            }

            name_index++;
        }

        if (row_index != row_count - 1) {
            mx_printchar('\n');
        }

        row_index++;
        col_count += col_count_tmp;
    }
}

static void mx_print_spaces(t_item **names, int index, int max_len) {
    if (names[index + 1]) {
        mx_print_spaces_fl_g(mx_strlen(names[index]->name), max_len);
    }
}

static void mx_print_row(t_item **names, int start, int step, int num, int max_len) {
    int i = start;

    while (i < num) {
        mx_printstr_fl_g(names[i]);
        mx_print_spaces(names, i, max_len);
        i += step;
    }
}

static void mx_print_names_in_cols_b(t_item **names, int rows, int num, int max_len) {
    int i = 0;

    while (i < rows) {
        mx_print_row(names, i, rows, num, max_len);

        if (i != rows - 1) {
            mx_printchar('\n');
        }

        i++;
    }
}

static void mx_print_names(t_item **names, int max_len, int wincol, t_uls_flags *uls_flags) {
    int num = 0;

    while(names[num]) {
        num++;
    }

    int cols = (wincol / max_len) != 0 ? wincol / max_len : 1;

    if (max_len * cols > wincol && cols != 1) {
        cols--;
    }

    int rows = 0;

    if (num * max_len > wincol) {
        rows = num / cols;

        if (rows == 0 || num % cols != 0) {
            rows += 1;
        }

        if (uls_flags->x == 0) {
            mx_print_names_in_cols_b(names, rows, num, max_len);
        } 
        else {
            mx_print_names_in_cols_a(names, rows, cols, max_len);
        }

    } 
    else {
        mx_print_row_fl_g(names, max_len);
    }

    mx_printchar('\n');
}

void mx_output_fl_g(t_item **names, t_uls_flags *uls_flags) {
    if (!names) {
        return;
    }

    int max_len = mx_max_len_fl_g(names);

    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    mx_print_names(names, max_len, win.ws_col, uls_flags);
}
