/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_st
*/

#include "corewar.h"

int instruct_st(INSTRUCT_PARAMS)
{
    if (!is_register(instruct, 2))
        return -1;

    int value = get_value(champion, corewar->arena,
                        get_arg_type(instruct.byte, 0),
                        instruct.args[0].val, VAL_NORMAL);

    if (instruct.args[1].type == T_REG) {
        champion->registers[instruct.args[1].val - 1] = value;
        return 0;
    }

    int pos = (champion->pc + (instruct.args[1].val % IDX_MOD + MEM_SIZE))
                                                    % MEM_SIZE;
    write_arg(corewar->arena, pos, value);

    return 0;
}
