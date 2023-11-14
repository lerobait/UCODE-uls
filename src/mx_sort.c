#include "../inc/uls.h"

static int mx_calc_arr_len(t_item **dis) {
	int i = 0;

	while(dis[i]) {
		i++;
	}

	return i;
}

static void mx_swap_item(t_item **bond_first, t_item **bond_second) {
    t_item *tmp = *bond_first;

    *bond_first = *bond_second;
    *bond_second = tmp;
}

void mx_sort(t_item ***dis, t_uls_flags *uls_flags) {
    t_item **bond = *dis;
    int size = mx_calc_arr_len(bond);
    int i = 0, k;

    while (i < size) {
        k = i + 1;

        while (k < size) {
            if (bond[i]->error != NULL) {
                if (mx_strcmp(bond[i]->name, bond[k]->name) == 1)
                    mx_swap_item(&(bond[i]), &(bond[k]));
            }
            else if (mx_entrcmp(bond[i], bond[k], uls_flags) == uls_flags->r) {
                mx_swap_item(&(bond[i]), &(bond[k]));
            }

            k++;
        }

        i++;
    }
}
