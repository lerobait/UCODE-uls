#include "../inc/uls.h"

static t_item** mx_allocate_memory(int size) {
    if (size > 0) {
        return malloc((size + 1) * sizeof(t_item *));
    }

    return NULL;
}

void mx_sort_and_allocate_args(t_item ***files, t_item ***dirs, t_item ***errors, t_item ***args) {
    int i = 0;
    int s_files = 0;
    int s_err = 0;
    int s_dir = 0;

    while ((*args)[i] != NULL) {
        if ((*args)[i]->error == NULL) {
            if (!IS_DIRECTORY((*args)[i]->inf.st_mode)) {
                s_files++;
            } 
            else {
                s_dir++;
            }
        } 
        else {
            s_err++;
        }
        
        i++;
    }

    *files = mx_allocate_memory(s_files);
    *dirs = mx_allocate_memory(s_dir);
    *errors = mx_allocate_memory(s_err);
}
