/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** args
*/

#include "corewar.h"

int check_index_need(int index)
{
    return ((index >= OP_TYPE_ZJMP && index <= OP_TYPE_FORK)
            || index == OP_TYPE_LLDI || index == OP_TYPE_LFORK);
}

int read_arg(char* arena, int offset, int size)
{
    int arg = (arena[offset] >> 7) ? -1 : 0;

    for (int i = 0; i < size; i++) {
        arg <<= 8;
        arg |= (arena[(offset + i) % MEM_SIZE] & 0xFF);
    }

    return arg;
}

void write_arg(char* arena, int offset, int value)
{
    value = my_htobe32(value);

    byte_t byte1 = value & 0xFF;
    byte_t byte2 = (value >> 8) & 0xFF;
    byte_t byte3 = (value >> 16) & 0xFF;
    byte_t byte4 = (value >> 24) & 0xFF;

    arena[offset] = byte1;
    offset = (offset + 1) % MEM_SIZE;
    arena[offset] = byte2;
    offset = (offset + 1) % MEM_SIZE;
    arena[offset] = byte3;
    offset = (offset + 1) % MEM_SIZE;
    arena[offset] = byte4;
}

int get_arg_type(byte_t byte, int arg)
{
    int shift = 6 - (arg * 2);
    int mask = 0b11;
    return (byte >> shift) & mask;
}

int get_arg_len(int arg_type, int index)
{
    if (arg_type == T_REG)
        return 1;
    if (arg_type == T_DIR)
        return check_index_need(index) ? IND_SIZE : DIR_SIZE;
    return IND_SIZE;
}
