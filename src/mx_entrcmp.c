#include "../inc/uls.h"

static int mx_cmp_names(t_item *item_first, t_item *item_second) {
    return mx_strcmp(item_first->name, item_second->name);
}

static int mx_cmp_times(t_item *item_first, t_item *item_second) {
    if (item_first->inf.st_ctime == item_second->inf.st_ctime) {
        if (item_first->inf.st_ctimespec.tv_nsec == item_second->inf.st_ctimespec.tv_nsec) {
            return mx_cmp_names(item_first, item_second);
        }

        return (item_first->inf.st_ctimespec.tv_nsec < item_second->inf.st_ctimespec.tv_nsec) ? 1 : 0;
    }

    return (item_first->inf.st_ctime < item_second->inf.st_ctime) ? 1 : 0;
}

static int mx_entrcmp_3(t_item *item_first, t_item *item_second, t_uls_flags *uls_flags) {
    if (uls_flags->c == 1 && uls_flags->t == 1 && uls_flags->S != 1) {
        return mx_cmp_times(item_first, item_second);
    }
    else if (uls_flags->t != 1 && uls_flags->S != 1) {
        if (mx_cmp_names(item_first, item_second) > 0) {
            return 1;
        }
    }

    return 0;
}

static int mx_entrcmp_2(t_item *item_first, t_item *item_second, t_uls_flags *uls_flags) {
    if (uls_flags->u == 1 && uls_flags->t == 1 && uls_flags->S != 1) {
        bool is_time_equal = item_first->inf.st_atime == item_second->inf.st_atime;
        bool is_nano_time_equal = item_first->inf.st_atimespec.tv_nsec == item_second->inf.st_atimespec.tv_nsec;
        bool is_first_nano_time_less = item_first->inf.st_atimespec.tv_nsec < item_second->inf.st_atimespec.tv_nsec;
        bool is_first_time_less = item_first->inf.st_atime < item_second->inf.st_atime;

        if (is_time_equal) {
            if (is_nano_time_equal) {
                return mx_strcmp(item_first->name, item_second->name);
            }

            return is_first_nano_time_less ? 1 : 0;
        }

        return is_first_time_less ? 1 : 0;
    }
    else {
        return mx_entrcmp_3(item_first, item_second, uls_flags);
    }
}

int mx_entrcmp(t_item *item_first, t_item *item_second, t_uls_flags *uls_flags) {
    if (uls_flags->S == 1) {
        if (item_first->inf.st_size != item_second->inf.st_size) {
            return item_first->inf.st_size < item_second->inf.st_size ? 1 : 0;
        }

        return mx_strcmp(item_first->name, item_second->name);
    }
    
    if (uls_flags->t == 1 && uls_flags->c != 1 && uls_flags->u != 1) {
        if (item_first->inf.st_mtime != item_second->inf.st_mtime) {
            return item_first->inf.st_mtime < item_second->inf.st_mtime ? 1 : 0;
        }

        if (item_first->inf.st_mtimespec.tv_nsec != item_second->inf.st_mtimespec.tv_nsec) {
            return item_first->inf.st_mtimespec.tv_nsec < item_second->inf.st_mtimespec.tv_nsec ? 1 : 0;
        }

        return mx_strcmp(item_first->name, item_second->name);
    }
    
    return mx_entrcmp_2(item_first, item_second, uls_flags);
}
