#include "../inc/uls.h"

int mx_count_directory_entries(t_item **arg, t_uls_flags *uls_flags) {
    int count = 0;
    t_item *args = *arg;
    DIR *directory_pointer;
    struct dirent *directory_entry;

    if (IS_DIRECTORY(args->inf.st_mode) || IS_LINK(args->inf.st_mode)) {
        directory_pointer = opendir(args->path);

        if (directory_pointer != NULL) {
            while ((directory_entry = readdir(directory_pointer)) != NULL) {
                if (directory_entry->d_name[0] != '.' || mx_check_a(directory_entry->d_name, uls_flags) == 1) {
                    count++;
                }
            }

            closedir(directory_pointer);

        }
        else {
            (*arg)->error = mx_strdup(strerror(errno));
            uls_flags->ex = 1;
            return -1;
        }
    }
    
    return count;
}
