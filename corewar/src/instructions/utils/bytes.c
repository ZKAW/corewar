/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** bytes
*/

#include "corewar.h"

int get_arg_from_byte(char args)
{
    int code = args & 0b11;
    return ARG_TYPES[code];
}

static int get_exceptions(int val)
{
    if (val == 0)
        return DIR_SIZE;
    if (val == 8 || val == 11 || val == 14)
        return IND_SIZE;
    return 0;
}

static int get_bytes_from_type(int type)
{
    if (type == 1)
        return 1;
    if (type == 2)
        return DIR_SIZE;
    if (type == 4)
        return IND_SIZE;
    return 0;
}

int count_instr_bytes(byte_t byte, int idx)
{
    int bytes = 2;
    int i = 4;
    int tmp = 0;

    if (byte == 0)
        return 1 + get_exceptions(idx);
    for (; i > op_tab[idx].nbr_args; i--)
        byte >>= 2;
    for (; i > 0; i--) {
        tmp = get_arg_from_byte(byte);
        if (tmp == -1)
            return -1;
        if (tmp == T_DIR && check_index_need(idx) == 1)
            bytes += IND_SIZE;
        else
            bytes += get_bytes_from_type(tmp);
        byte >>= 2;
    }
    return bytes;
}
