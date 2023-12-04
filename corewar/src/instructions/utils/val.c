/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** val
*/

#include "corewar.h"

int get_value(VAL_PARAMS)
{
    if (byte == T_REG)
        return champion->registers[value - 1];
    if (byte == T_DIR)
        return value;

    int addr = (type == VAL_LONG) ? (champion->pc + value) % MEM_SIZE :
            (champion->pc + (value % IDX_MOD)) % MEM_SIZE;

    addr = (addr < 0) ? (addr + MEM_SIZE) : addr;
    return read_arg(arena, addr, REG_SIZE);
}
