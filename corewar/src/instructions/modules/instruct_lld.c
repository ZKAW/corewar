/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_lld
*/

#include "corewar.h"

int instruct_lld(INSTRUCT_PARAMS)
{
    if (!is_register(instruct, 2))
        return -1;

    champion->registers[instruct.args[1].val - 1] = get_value(champion,
                                            corewar->arena,
                                            get_arg_type(instruct.byte, 0),
                                            instruct.args[0].val, VAL_NORMAL);
    champion->carry = (!champion->registers[instruct.args[1].val - 1]) ? 1 : 0;
    return 0;
}
