#include "../inc/uls.h"

static char *mx_check_passw(t_item *total) {
    struct passwd *pw = getpwuid(total->inf.st_uid);
    return pw ? mx_strdup(pw->pw_name) : mx_itoa(total->inf.st_uid);
}

static char *mx_check_grp(t_item *total) {
    struct group *grp = getgrgid(total->inf.st_gid);
    char *name = grp ? mx_strdup(grp->gr_name) : mx_itoa(total->inf.st_gid);
    return name;
}

void mx_count_sz(t_size *sz, t_item *total) {

    if (sz->link < total->inf.st_nlink) { //FIX
        sz->link = total->inf.st_nlink;
    }

    if (sz->size < total->inf.st_size) {
        sz->size = total->inf.st_size;
    }

    char *name_grp = mx_check_grp(total);

    if (name_grp != NULL) {

        if (sz->group < mx_strlen(name_grp)) { //FIX
            sz->group = mx_strlen(name_grp);
        }

        free(name_grp);
    }

    char *name_pw = mx_check_passw(total);

    if (name_pw != NULL) {

        if (sz->user < mx_strlen(name_pw)) { //FIX
            sz->user = mx_strlen(name_pw);
        }

        free(name_pw);
    }
}
