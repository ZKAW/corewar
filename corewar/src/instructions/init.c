/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** init
*/

#include "corewar.h"

arg_type_t get_instruct_type(int arg, byte_t byte)
{
    int shift_amount = 6 - (arg * 2);
    int mask = 0b11;
    int type = (byte >> shift_amount) & mask;

    return type;
}

instruct_t init_instructs(champion_t *champion, char* arena, int idx)
{
    instruct_t instructs = {0};
    instructs.byte = arena[(champion->pc + 1) % MEM_SIZE];
    int offset = (champion->pc + 2) % MEM_SIZE;

    if (!PASS_ARGS(idx)) {
        offset = (offset - 1 + MEM_SIZE) % MEM_SIZE;
        int arg_len = get_arg_len(GET_ARG_PARAM(idx), idx);
        instructs.args[0].val = read_arg(arena, offset, arg_len);
        instructs.args[0].type = get_instruct_type(0, instructs.byte);
        offset = (offset + arg_len) % MEM_SIZE;
        return instructs;
    }
    for (int i = 0; i < op_tab[idx].nbr_args; i++) {
        char arg_type = get_arg_type(instructs.byte, i);
        int arg_len = get_arg_len(arg_type, idx);
        instructs.args[i].val = read_arg(arena, offset, arg_len);
        instructs.args[i].type = get_instruct_type(i, instructs.byte);
        offset = (offset + arg_len) % MEM_SIZE;
    }
    return instructs;
}
