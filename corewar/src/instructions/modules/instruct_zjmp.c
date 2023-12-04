/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_zjmp
*/

#include "corewar.h"

int instruct_zjmp(INSTRUCT_PARAMS)
{
    if (champion->carry != 1)
        return 0;

    champion->pc = (champion->pc + (instruct.args[0].val % IDX_MOD)
                    - 3 + MEM_SIZE) % MEM_SIZE;

    return 0;
}
