#include "../inc/uls.h"

static void mx_print_name(t_item *args) {
    mx_printstr(args->name);
    mx_printstr(LS_COLOR_RESET);
}

static int mx_print_first(t_item *args) {
    char *clr;

    if (IS_DIRECTORY(args->inf.st_mode)) {
        clr = "\033[34m";
    }
    else if (IS_LINK(args->inf.st_mode)) {
        clr = "\033[35m";
    }
    else if (args->inf.st_mode & S_IXOTH) {
        clr = LS_COLOR_RED;
    }
    else {
        return 0;
    }

    mx_printstr(clr);
    mx_print_name(args);
    return 1;
}

static int mx_print_sec(t_item *args) {
    char *clr_code = NULL;

    if (IS_BLOCK(args->inf.st_mode)) {
        clr_code = "\033[34;46m";
    }
    else if (IS_CHAR(args->inf.st_mode)) {
        clr_code = "\033[34;43m";
    }
    else if (IS_SOCKET(args->inf.st_mode)) {
        clr_code = "\033[32m";
    }

    if (clr_code != NULL) {
        mx_printstr(clr_code);
        mx_print_name(args);
        return 1;
    }

    return 0;
}

void mx_printstr_fl_g(t_item *args) {
    if (mx_print_first(args) == 1 || mx_print_sec(args) == 1) {
        return;
    }

    if (IS_FIFOFILE(args->inf.st_mode)) {
        mx_printstr("\033[33m");
    } 
    else if (IS_WHITEOUT(args->inf.st_mode)) {
        mx_printstr("\033[36m");
    } 
    else if (IS_EXEC(args->inf.st_mode)) {
        mx_printstr("\033[31m");
    }

    if (IS_FIFOFILE(args->inf.st_mode) || IS_WHITEOUT(args->inf.st_mode) || IS_EXEC(args->inf.st_mode)) {
        mx_print_name(args);
    } 
    else {
        mx_printstr(args->name);
    }
}
