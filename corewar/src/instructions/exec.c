/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** exec
*/

#include "corewar.h"

void exec_instruction(corewar_t *corewar, champion_t *champion)
{
    int idx = corewar->arena[champion->pc] - 1;
    if (!check_instruct_validity(corewar->arena, champion, idx)) {
        champion->pc = (champion->pc + 1) % MEM_SIZE;
        return;
    }
    byte_t byte = GET_PARAM_BYTE(corewar->arena, champion, idx);
    instruct_t instructs = init_instructs(champion, corewar->arena, idx);

    op_tab[idx].func(corewar, champion, instructs) == -1 ?
        freeze_champ_once(champion) :
        freeze_champ_by_cycles(champion, byte, idx);
}
