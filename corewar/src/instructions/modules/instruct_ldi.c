/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_ldi
*/

#include "corewar.h"

int instruct_ldi(INSTRUCT_PARAMS)
{
    if (!is_register(instruct, 3))
        return -1;

    int val1 = get_value(champion, corewar->arena,
                        get_arg_type(instruct.byte, 0),
                        instruct.args[0].val, VAL_NORMAL);
    int val2 = get_value(champion, corewar->arena,
                        get_arg_type(instruct.byte, 1),
                        instruct.args[1].val, VAL_NORMAL);
    int position = (champion->pc + ((val1 + val2) % IDX_MOD + MEM_SIZE))
                        % MEM_SIZE;
    champion->registers[instruct.args[2].val - 1] = read_arg(corewar->arena,
                                                position, REG_SIZE);
    champion->carry = (!champion->registers[instruct.args[2].val - 1]) ? 1 : 0;
    return 0;
}
