#include "../inc/uls.h"

char mx_get_acl(t_item *print) {
    if (listxattr(print->path, NULL, 0, XATTR_NOFOLLOW) > 0) {
        return ('@');
    }

    acl_t tmp = acl_get_file(print->path, ACL_TYPE_EXTENDED);

    if (tmp) {
        acl_free(tmp);
        return ('+');
    }
    
    return (' ');
}
