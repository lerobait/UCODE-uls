#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <errno.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/types.h>
#include <sys/xattr.h>

#define IS_DIRECTORY(mode) (((mode) & S_IFMT) == S_IFDIR)
#define IS_BLOCK(mode) (((mode) & S_IFMT) == S_IFBLK)
#define IS_CHAR(mode) (((mode) & S_IFMT) == S_IFCHR)
#define IS_LINK(mode) (((mode) & S_IFMT) == S_IFLNK)
#define IS_FIFOFILE(mode) (((mode) & S_IFMT) == S_IFIFO)
#define IS_SOCKET(mode) (((mode) & S_IFMT) == S_IFSOCK)
#define IS_WHITEOUT(mode) (((mode) & S_IFMT) == S_IFWHT)
#define IS_EXEC(mode) ((mode) & S_IXUSR)

#define LS_COLOR_RED        "\x1b[31m"
#define LS_COLOR_RESET      "\x1b[0m"

typedef struct uls_flags {
    int A;
    int C;
    int R;
    int S;
    int T;
    int G;
    int x;
    int l;
    int t;
    int u;
    int r;
    int a;
    int c;
    int o;
    int g;
    int m;
    int ex;
    int files;
    int force;
}           t_uls_flags;

typedef struct s_item {
    char *path;
    char *name;
    char *error;
    struct stat inf;
    struct s_item **open;
}               t_item;

typedef struct s_type {
    int i;
    int s_f;
    int s_e;
    int s_d;
}               t_type;

typedef struct s_size {
    int group;
    int user;
    int size;
    int link;
    bool dev;
}               t_size;

//Flags
t_uls_flags *mx_extr_flags_from_args(char *argv[], int *i);
void mx_set_flags_from_char(t_uls_flags **uls_flags, char flag);
void mx_set_secondary_flags(t_uls_flags **uls_flags, char flag);
void mx_process_output_flags(t_uls_flags **uls_flags, char flag);
void mx_reset_output_flags(t_uls_flags **uls_flags);
void mx_handle_invalid_flag(t_uls_flags **uls_flags, char flag);

//Names
t_item **mx_create_name_list(int argc, char **argv, int i);
char **mx_dup_args(int argc, char **argv, int i, int *count);
t_item **mx_generate_item_arr(char **name, int count);
t_item *mx_make_item_node(char *data);

//Dirrectory
void mx_handle_dir_operation(t_item ***args, t_uls_flags *uls_flags);
t_item **mx_process_files_and_dirs(t_item ***args, t_uls_flags *uls_flags);
t_type *mx_new_num();
void mx_sort_and_allocate_args(t_item ***files, t_item ***dirs, t_item ***errors, t_item ***args);
void mx_split_files_and_dirs(t_item **args, t_type *number, t_item ***files, t_item ***dirs);
t_item *mx_new_file_node(t_item *arg);
void mx_clear_item_arr(t_item ***args, t_item **dirs);
void open_dir(t_item ***args, t_uls_flags *uls_flags);
int mx_count_directory_entries(t_item **arg, t_uls_flags *uls_flags);
int mx_check_a(char *name, t_uls_flags *uls_flags);
t_item *mx_create_new_node(char *name, char *path);
void mx_join(char **res, char *s2);
void mx_out_put_all(t_item ***args, t_uls_flags *uls_flags);
void mx_output_err_open(t_item **args, t_uls_flags *uls_flags);

//Sort
void mx_sort(t_item ***dis, t_uls_flags *uls_flags);
int mx_entrcmp(t_item *item_first, t_item *item_second, t_uls_flags *flags);

//Output
void mx_output_menu_with_flags(t_item ***names, t_uls_flags *uls_flags, int flag);
void mx_output_fl_l(t_item **names, t_uls_flags *uls_flags, int flag);
void mx_new_size(t_size *sz);
void mx_count_sz(t_size *sz, t_item *total);
bool mx_check_dev(t_item **names, t_size *sz);
void mx_print_all_details(t_item *print, t_size *sz, t_uls_flags *uls_flags);
void mx_print_unix_permissions(t_item *print);
char mx_check_unix_permissions(t_item *print);
char mx_get_acl(t_item *print);
void mx_print_aligned_link(t_item *print, t_size *sz);
void mx_get_usr_name(t_item *print, int usr);
void mx_get_grp_name(t_item *print, int grp);
void mx_print_sz(t_item *print, t_size *sz);
void mx_print_double_cases(t_item *print, t_size *sz);
void mx_new_time(t_item *print, char *t, t_uls_flags *uls_flags);
void mx_print_color_and_lnk(t_item *print, t_uls_flags *uls_flags);
void mx_printstr_fl_g(t_item *args);
void mx_output_fl_c(t_item **names);
int mx_names_max_len(t_item **names);
void mx_print_tab(int len, int max_len);
void mx_output_fl_x(t_item **names);
void mx_output_fl_m(t_item **names, t_uls_flags *uls_flags);
void mx_output_fl_1(t_item **names, t_uls_flags *uls_flags);
void mx_output_fl_g(t_item **names, t_uls_flags *uls_flags);

//Delete
void mx_del_double_arr(t_item ***args);
void mx_del_files(t_item ***args, t_uls_flags *uls_flags);


//Errors
void mx_printerr(const char *s);
void print_errmessage(char flag);
void mx_output_errmessage(t_item ***errors, t_uls_flags *uls_flags);

#endif
