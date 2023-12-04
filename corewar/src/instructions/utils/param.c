/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** tools
*/

#include "corewar.h"

int get_param_value(char *arena, int pc, int size)
{
    int value = 0;
    int i = 0;

    for (i = 0; i < size; i += 1) {
        value = value << 8;
        value += arena[(pc + i) % MEM_SIZE];
    }
    return (value);
}

int get_param_type(char *arena, int pc, int size)
{
    int value = 0;
    int i = 0;

    for (i = 0; i < size; i += 1) {
        value = value << 8;
        value += arena[(pc + i) % MEM_SIZE];
    }
    if (value == 1)
        return (T_REG);
    if (value == 2)
        return (T_DIR);
    if (value == 4)
        return (T_IND);
    return (T_NONE);
}
