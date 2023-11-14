#include "../inc/uls.h"

char **mx_dup_args(int argc, char **argv, int i, int *count) {
    char **names = NULL;
    int j = i;

    if (i == argc) {
        *count = 2;
        names = malloc(2 * sizeof(char *));
        names[0] = mx_strdup(".");
        names[1] = NULL;
    }
    else {
        while (argv[j]) {
            j++;
        }

        names = malloc((j - i + 1) * sizeof(char *));
        j = 0;

        while (argv[i]) {
            names[j] = mx_strdup(argv[i]);
            i++;
            j++;
        }

        names[j] = NULL;
        *count = j + 1;
    }

    return names;
}
