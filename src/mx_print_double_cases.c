#include "../inc/uls.h"

static char *mx_minor_to_hex(char *min) {
    char *hex_min = mx_strdup("0x00000000");
    int min_len = mx_strlen(min);
    int offset = 10 - min_len;

    mx_strcpy(hex_min + offset, min);
    mx_strdel(&min);

    return hex_min;
}

static char *mx_get_minor(t_item *print) {
    int min_num = (int)(print->inf.st_rdev & 0xffffff);
    return min_num > 255 ? mx_minor_to_hex(mx_nbr_to_hex(min_num)) : mx_itoa(min_num);
}

static char *mx_get_major(t_item *print) {
    return mx_itoa((int)(((unsigned int)print->inf.st_rdev >> 24) & 0xff));
}

static void mx_print_spaces(int size) {
    for(int i = 0; i <= size; i++) {
        mx_printchar(' ');
    }
}

static void print_dev_inf(char *maj, char *min) {
    mx_print_spaces(2 - mx_strlen(maj));
    mx_printstr(maj);
    mx_printchar(',');
    mx_printchar(' ');
    mx_print_spaces(2 - mx_strlen(min));
    mx_printstr(min); 
}

static void mx_print_sz_inf(t_item *print) {
    mx_printstr("       ");
    mx_printint(print->inf.st_size);
}

void mx_print_double_cases(t_item *print, t_size *sz) {
    char *maj = mx_get_major(print);
    char *min = mx_get_minor(print);
    
    if (sz->dev == true) {
        if (IS_BLOCK(print->inf.st_mode) || IS_CHAR(print->inf.st_mode)) {
            print_dev_inf(maj, min);
        } 
        else {
            mx_print_sz_inf(print);
        }

    } 
    else {
        mx_print_sz_inf(print);
    }
    
    free(maj);
    free(min);
}
