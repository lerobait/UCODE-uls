#include "../inc/uls.h"

static void mx_read_dir(t_item ***args, int i, DIR *dptr, t_uls_flags *uls_flags) {
    struct dirent *ds;
    int count = 0;

    while ((ds = readdir(dptr)) != NULL) {
        if (ds->d_name[0] != '.' || mx_check_a(ds->d_name, uls_flags) == 1) {
            (*args)[i]->open[count++] = mx_create_new_node(ds->d_name, (*args)[i]->path);
        }
    }

    (*args)[i]->open[count] = NULL;
}

static void mx_allocate_memory_and_open_dir(t_item ***args, int i, int count, t_uls_flags *uls_flags) {
    DIR *dptr;
    (*args)[i]->open = malloc((count + 1) * sizeof(t_item *));
    if ((dptr = opendir((*args)[i]->path)) != NULL) {
        mx_read_dir(args, i, dptr, uls_flags);
        closedir(dptr);
    }
}

void open_dir(t_item ***args, t_uls_flags *uls_flags) {
    int i = 0;

    while ((*args)[i] != NULL) {
        int count = mx_count_directory_entries(&(*args)[i], uls_flags);

        if (count > 0) {
            mx_allocate_memory_and_open_dir(args, i, count, uls_flags);
        }

        i++;
    }

    mx_out_put_all(args, uls_flags);
}
