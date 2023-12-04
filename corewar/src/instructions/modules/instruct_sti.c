/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruct_sti
*/

#include "corewar.h"

int instruct_sti(INSTRUCT_PARAMS)
{
    if (!is_register(instruct, 3))
        return -1;

    int val1 = get_value(champion, corewar->arena,
                        get_arg_type(instruct.byte, 0),
                        instruct.args[0].val, VAL_NORMAL);
    int val2 = get_value(champion, corewar->arena,
                        get_arg_type(instruct.byte, 1),
                        instruct.args[1].val, VAL_NORMAL);
    int val3 = get_value(champion, corewar->arena,
                        get_arg_type(instruct.byte, 2),
                        instruct.args[2].val, VAL_NORMAL);

    int pos = (champion->pc + ((val2 + val3) % IDX_MOD + MEM_SIZE)) % MEM_SIZE;
    write_arg(corewar->arena, pos, val1);

    return 0;
}
