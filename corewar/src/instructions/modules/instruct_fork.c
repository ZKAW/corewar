/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_fork
*/

#include "corewar.h"

int instruct_fork(INSTRUCT_PARAMS)
{
    champion_t *forked_champion = copy_champion(champion);

    if (!forked_champion) {
        return -1;
    }

    forked_champion->fd = -1;
    forked_champion->is_forked = true;
    forked_champion->freeze_duration = op_tab[OP_TYPE_FORK].nbr_cycles;
    forked_champion->pc = (champion->pc + (instruct.args[0].val % IDX_MOD)
                        + MEM_SIZE) % MEM_SIZE;

    append_champion(corewar, forked_champion);

    return 0;
}
