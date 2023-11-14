#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (n != 0) {
        const char *str1 = s1;
        const char *str2 = s2;

        for (size_t i = 0; i < n; ++i) {
            if (str1[i] != str2[i])
                return str1[i] - str2[i];
        }
        return 0;
    }
    else
        return 0;
}
