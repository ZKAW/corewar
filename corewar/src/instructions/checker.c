/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** checker
*/

#include "corewar.h"

static int check_param_bytes(int idx, char args)
{
    args >>= 2 * (4 - op_tab[idx].nbr_args);

    for (int i = op_tab[idx].nbr_args; i > 0; i--) {
        if ((args & 0x03) != get_arg_from_byte(args & 0x03)
            || !(get_arg_from_byte(args & 0x03) & op_tab[idx].type[i - 1]))
            return -1;
        args >>= 2;
    }

    return 0;
}

int check_instruct_validity(char *arena, champion_t *champion, int idx)
{
    if (idx < 0 || idx > (OP_NB - 2))
        return false;
    if (!PASS_ARGS(idx))
        return true;
    if (check_param_bytes(idx, arena[(champion->pc + 1) % MEM_SIZE]) == -1)
        return false;
    return true;
}
